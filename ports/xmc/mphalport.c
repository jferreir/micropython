/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2019 Damien P. George
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

#include "py/mpstate.h"
#include "py/mphal.h"
#include "lib/utils/interrupt_char.h"
#include "ringbuff/ringbuff.h"

#include "mpconfigboard.h"

volatile uint32_t systick_ms;

void SysTick_Handler(void) 
{
    systick_ms++;
}

static const XMC_UART_CH_CONFIG_t uart_config =
{
    .baudrate = SERIAL_BAUDRATE,
    .data_bits = 8,
    .stop_bits = 1,
};

static ringbuff_t serial_buff;
static uint8_t serial_buff_data[SERIAL_BUFF_SIZE];

int32_t serial_init(void)
{
    ringbuff_init(&serial_buff, serial_buff_data, SERIAL_BUFF_SIZE);

    XMC_UART_CH_Init(SERIAL_UART, &uart_config);

    XMC_GPIO_SetMode(SERIAL_RX_PIN, XMC_GPIO_MODE_INPUT_PULL_UP);
    XMC_UART_CH_SetInputSource(SERIAL_UART, XMC_UART_CH_INPUT_RXD, SERIAL_RX_INPUT);

    /* Set service request for receive interrupt */
    XMC_USIC_CH_SetInterruptNodePointer(SERIAL_UART, XMC_USIC_CH_INTERRUPT_NODE_POINTER_RECEIVE, 0U);
    XMC_USIC_CH_SetInterruptNodePointer(SERIAL_UART, XMC_USIC_CH_INTERRUPT_NODE_POINTER_ALTERNATE_RECEIVE, 0U);

  /*Set priority and enable NVIC node for receive interrupt*/
#if UC_FAMILY == XMC4
    NVIC_SetPriority(SERIAL_RX_IRQN, NVIC_EncodePriority(NVIC_GetPriorityGrouping(), 62, 0));
#else
    NVIC_SetPriority(SERIAL_RX_IRQN, 3);
#endif
    NVIC_EnableIRQ(SERIAL_RX_IRQN);

    XMC_UART_CH_EnableEvent(SERIAL_UART, XMC_UART_CH_EVENT_STANDARD_RECEIVE | XMC_UART_CH_EVENT_ALTERNATIVE_RECEIVE);

    XMC_UART_CH_Start(SERIAL_UART);

    XMC_GPIO_SetMode(SERIAL_TX_PIN, SERIAL_TX_PIN_AF);

    return 0;
}

void SERIAL_RX_IRQHandler(void)
{
  static uint8_t data;

  data = XMC_UART_CH_GetReceivedData(SERIAL_UART);

  ringbuff_write(&serial_buff, &data, 1);
}

#if MICROPY_KBD_EXCEPTION

void mp_hal_set_interrupt_char(int c) 
{
}

#endif

void mp_hal_delay_ms(mp_uint_t ms) 
{
    ms += 1;
    uint32_t t0 = systick_ms;
    while (systick_ms - t0 < ms) {
        MICROPY_EVENT_POLL_HOOK
    }
}

void mp_hal_delay_us(mp_uint_t us) 
{
    uint32_t ms = us / 1000 + 1;
    uint32_t t0 = systick_ms;
    while (systick_ms - t0 < ms) {
        __WFI();
    }
}

int mp_hal_stdin_rx_chr(void) 
{
    uint8_t data;
    for (;;) {
        if (ringbuff_read(&serial_buff, &data, sizeof(data)) > 0)
        {
            return data;
        }
        __WFI();
    }
}

void mp_hal_stdout_tx_strn(const char *str, mp_uint_t len) 
{
    while (len--) {
        XMC_UART_CH_Transmit(SERIAL_UART, *(const uint8_t *)str++);
    }
}

