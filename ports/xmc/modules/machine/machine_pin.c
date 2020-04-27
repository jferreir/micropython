/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014, 2015 Damien P. George
 * Copyright (c) 2016 Linaro Limited
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

#include <stdio.h>
#include <string.h>

#include "xmc_gpio.h"

#include "py/runtime.h"
#include "py/mphal.h"
#include "mphalport.h"
#include "modmachine.h"
#include "extmod/virtpin.h"

#include "pins.h"

extern const mp_obj_dict_t pin_board_pins_locals_dict;

static const int8_t device_gpio_port0_pins[16]  = {   P0_0_ATTR,   P0_1_ATTR,   P0_2_ATTR,   P0_3_ATTR,   P0_4_ATTR,   P0_5_ATTR,   P0_6_ATTR,   P0_7_ATTR,   P0_8_ATTR,   P0_9_ATTR,  P0_10_ATTR,  P0_11_ATTR,  P0_12_ATTR,  P0_13_ATTR,  P0_14_ATTR,  P0_15_ATTR};
static const int8_t device_gpio_port1_pins[16]  = {   P1_0_ATTR,   P1_1_ATTR,   P1_2_ATTR,   P1_3_ATTR,   P1_4_ATTR,   P1_5_ATTR,   P1_6_ATTR,   P1_7_ATTR,   P1_8_ATTR,   P1_9_ATTR,  P1_10_ATTR,  P1_11_ATTR,  P1_12_ATTR,  P1_13_ATTR,  P1_14_ATTR,  P1_15_ATTR};
static const int8_t device_gpio_port2_pins[16]  = {   P2_0_ATTR,   P2_1_ATTR,   P2_2_ATTR,   P2_3_ATTR,   P2_4_ATTR,   P2_5_ATTR,   P2_6_ATTR,   P2_7_ATTR,   P2_8_ATTR,   P2_9_ATTR,  P2_10_ATTR,  P2_11_ATTR,  P2_12_ATTR,  P2_13_ATTR,  P2_14_ATTR,  P2_15_ATTR};
static const int8_t device_gpio_port3_pins[16]  = {   P3_0_ATTR,   P3_1_ATTR,   P3_2_ATTR,   P3_3_ATTR,   P3_4_ATTR,   P3_5_ATTR,   P3_6_ATTR,   P3_7_ATTR,   P3_8_ATTR,   P3_9_ATTR,  P3_10_ATTR,  P3_11_ATTR,  P3_12_ATTR,  P3_13_ATTR,  P3_14_ATTR,  P3_15_ATTR};
static const int8_t device_gpio_port4_pins[16]  = {   P4_0_ATTR,   P4_1_ATTR,   P4_2_ATTR,   P4_3_ATTR,   P4_4_ATTR,   P4_5_ATTR,   P4_6_ATTR,   P4_7_ATTR,   P4_8_ATTR,   P4_9_ATTR,  P4_10_ATTR,  P4_11_ATTR,  P4_12_ATTR,  P4_13_ATTR,  P4_14_ATTR,  P4_15_ATTR};
static const int8_t device_gpio_port5_pins[16]  = {   P5_0_ATTR,   P5_1_ATTR,   P5_2_ATTR,   P5_3_ATTR,   P5_4_ATTR,   P5_5_ATTR,   P5_6_ATTR,   P5_7_ATTR,   P5_8_ATTR,   P5_9_ATTR,  P5_10_ATTR,  P5_11_ATTR,  P5_12_ATTR,  P5_13_ATTR,  P5_14_ATTR,  P5_15_ATTR};
static const int8_t device_gpio_port6_pins[16]  = {   P6_0_ATTR,   P6_1_ATTR,   P6_2_ATTR,   P6_3_ATTR,   P6_4_ATTR,   P6_5_ATTR,   P6_6_ATTR,   P6_7_ATTR,   P6_8_ATTR,   P6_9_ATTR,  P6_10_ATTR,  P6_11_ATTR,  P6_12_ATTR,  P6_13_ATTR,  P6_14_ATTR,  P6_15_ATTR};
static const int8_t device_gpio_port7_pins[16]  = {   P7_0_ATTR,   P7_1_ATTR,   P7_2_ATTR,   P7_3_ATTR,   P7_4_ATTR,   P7_5_ATTR,   P7_6_ATTR,   P7_7_ATTR,   P7_8_ATTR,   P7_9_ATTR,  P7_10_ATTR,  P7_11_ATTR,  P7_12_ATTR,  P7_13_ATTR,  P7_14_ATTR,  P7_15_ATTR};
static const int8_t device_gpio_port8_pins[16]  = {   P8_0_ATTR,   P8_1_ATTR,   P8_2_ATTR,   P8_3_ATTR,   P8_4_ATTR,   P8_5_ATTR,   P8_6_ATTR,   P8_7_ATTR,   P8_8_ATTR,   P8_9_ATTR,  P8_10_ATTR,  P8_11_ATTR,  P8_12_ATTR,  P8_13_ATTR,  P8_14_ATTR,  P8_15_ATTR};
static const int8_t device_gpio_port9_pins[16]  = {   P9_0_ATTR,   P9_1_ATTR,   P9_2_ATTR,   P9_3_ATTR,   P9_4_ATTR,   P9_5_ATTR,   P9_6_ATTR,   P9_7_ATTR,   P9_8_ATTR,   P9_9_ATTR,  P9_10_ATTR,  P9_11_ATTR,  P9_12_ATTR,  P9_13_ATTR,  P9_14_ATTR,  P9_15_ATTR};
static const int8_t device_gpio_port14_pins[16] = {  P14_0_ATTR,  P14_1_ATTR,  P14_2_ATTR,  P14_3_ATTR,  P14_4_ATTR,  P14_5_ATTR,  P14_6_ATTR,  P14_7_ATTR,  P14_8_ATTR,  P14_9_ATTR, P14_10_ATTR, P14_11_ATTR, P14_12_ATTR, P14_13_ATTR, P14_14_ATTR, P14_15_ATTR};
static const int8_t device_gpio_port15_pins[16] = {  P15_0_ATTR,  P15_1_ATTR,  P15_2_ATTR,  P15_3_ATTR,  P15_4_ATTR,  P15_5_ATTR,  P15_6_ATTR,  P15_7_ATTR,  P15_8_ATTR,  P15_9_ATTR, P15_10_ATTR, P15_11_ATTR, P15_12_ATTR, P15_13_ATTR, P15_14_ATTR, P15_15_ATTR};

static const void *const device_gpio_ports_pins[16][2] =
{
#if defined(XMC_GPIO_PORT0)
    {XMC_GPIO_PORT0, device_gpio_port0_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT1)
    {XMC_GPIO_PORT1, device_gpio_port1_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT2)
    {XMC_GPIO_PORT2, device_gpio_port2_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT3)
    {XMC_GPIO_PORT3, device_gpio_port3_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT4)
    {XMC_GPIO_PORT4, device_gpio_port4_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT5)
    {XMC_GPIO_PORT5, device_gpio_port5_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT6)
    {XMC_GPIO_PORT6, device_gpio_port6_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT7)
    {XMC_GPIO_PORT7, device_gpio_port7_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT8)
    {XMC_GPIO_PORT8, device_gpio_port8_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT9)
    {XMC_GPIO_PORT9, device_gpio_port9_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT10)
    {XMC_GPIO_PORT10, device_gpio_port10_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT11)
    {XMC_GPIO_PORT11, device_gpio_port11_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT12)
    {XMC_GPIO_PORT12, device_gpio_port12_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT13)
    {XMC_GPIO_PORT13, device_gpio_port13_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT14)
    {XMC_GPIO_PORT14, device_gpio_port14_pins},
#else
    {NULL, NULL},
#endif

#if defined(XMC_GPIO_PORT15)
    {XMC_GPIO_PORT15, device_gpio_port15_pins},
#else
    {NULL, NULL},
#endif
};

typedef struct machine_pin_obj {
    mp_obj_base_t base;
    XMC_GPIO_PORT_t *port;
    uint32_t pin;
} machine_pin_obj_t;

const mp_obj_base_t machine_pin_obj_template = {&machine_pin_type};

STATIC void machine_pin_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) {
    machine_pin_obj_t *self = self_in;
    mp_printf(print, "<Pin %p %d>", self->port, self->pin);
}

// pin.init(mode, pull=None, *, value)
STATIC mp_obj_t machine_pin_obj_init_helper(machine_pin_obj_t *self, size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args) {
    enum { ARG_mode, ARG_pull, ARG_value, ARG_drive };
    static const mp_arg_t allowed_args[] = {
        { MP_QSTR_mode,  MP_ARG_REQUIRED | MP_ARG_INT },
        { MP_QSTR_pull,  MP_ARG_OBJ,                  {.u_obj = mp_const_none}},
        { MP_QSTR_value, MP_ARG_KW_ONLY | MP_ARG_OBJ, {.u_obj = MP_OBJ_NULL}},
        { MP_QSTR_drive, MP_ARG_KW_ONLY | MP_ARG_OBJ, {.u_obj = mp_const_none}},
    };

    // parse args
    mp_arg_val_t args[MP_ARRAY_SIZE(allowed_args)];
    mp_arg_parse_all(n_args, pos_args, kw_args, MP_ARRAY_SIZE(allowed_args), allowed_args, args);

    // get io mode
    XMC_GPIO_MODE_t mode = args[ARG_mode].u_int;

    if (mode == XMC_GPIO_MODE_INPUT_TRISTATE)
    {
      // get pull mode
      if (args[ARG_pull].u_obj != mp_const_none) {
          mode = mp_obj_get_int(args[ARG_pull].u_obj);
      }
    }

    XMC_GPIO_OUTPUT_LEVEL_t output_level = XMC_GPIO_OUTPUT_LEVEL_LOW;
    // get initial value
    if (args[ARG_value].u_obj != MP_OBJ_NULL) {
        output_level = mp_obj_is_true(args[ARG_value].u_obj) ? XMC_GPIO_OUTPUT_LEVEL_HIGH : XMC_GPIO_OUTPUT_LEVEL_LOW;
    }

    XMC_GPIO_OUTPUT_STRENGTH_t output_strength = XMC_GPIO_OUTPUT_STRENGTH_MEDIUM;
    if (args[ARG_drive].u_obj != mp_const_none) {
      output_strength = mp_obj_get_int(args[ARG_drive].u_obj);
    }

    XMC_GPIO_CONFIG_t gpio_config;
    gpio_config.mode = mode;
    gpio_config.output_level = output_level;
    gpio_config.output_strength = output_strength;
    XMC_GPIO_Init(self->port, self->pin, &gpio_config);

    return mp_const_none;
}

static XMC_GPIO_PORT_t *device_validate_gpio(int port, int pin)
{

    XMC_GPIO_PORT_t *gpio_port = (XMC_GPIO_PORT_t *)device_gpio_ports_pins[port][0];
    int8_t *gpio_port_pins = (int8_t *)device_gpio_ports_pins[port][1];
    if (gpio_port != NULL)
    {
        if (gpio_port_pins[pin] != 0)
        {
            return gpio_port;
        }
    }

    return NULL;
}

static int pin_find_named_pin(const mp_obj_dict_t *named_pins, mp_obj_t name) {
    const mp_map_t *named_map = &named_pins->map;
    mp_map_elem_t *named_elem = mp_map_lookup((mp_map_t*)named_map, name, MP_MAP_LOOKUP);
    if (named_elem != NULL && named_elem->value != MP_OBJ_NULL) {
        return mp_obj_get_int(named_elem->value);
    }
    return -1;
}

static machine_pin_obj_t *const pin_find(mp_obj_t user_obj) {
    int port_index;
    int pin_index;

    if (mp_obj_is_int(user_obj))
    {
        int id = mp_obj_get_int(user_obj);
        port_index = GPIO_GET_PORT(id);
        pin_index = GPIO_GET_PIN(id);

    }
    else if (mp_obj_is_str(user_obj)) {
        // check if named pin is in the board dictionary
        int id = pin_find_named_pin(&pin_board_pins_locals_dict, user_obj);
        if (id != -1)
        {
          port_index = GPIO_GET_PORT(id);
          pin_index = GPIO_GET_PIN(id);
        }
        else
        {
          mp_raise_ValueError("Pin doesn't exist");
          return NULL;
        }
    }
    else if (mp_obj_is_type(user_obj, &mp_type_list)) {
        mp_obj_t *items;
        mp_obj_get_array_fixed_n(user_obj, 2, &items);
        port_index = mp_obj_get_int(items[0]);
        pin_index = mp_obj_get_int(items[1]);
    }
    else
    {
        mp_raise_ValueError("invalid pin id");
        return NULL;
    }

    XMC_GPIO_PORT_t *gpio_port_ptr = device_validate_gpio(port_index, pin_index);
    if (!gpio_port_ptr) {
        mp_raise_ValueError("invalid port");
        return NULL;
    }

    machine_pin_obj_t *pin = m_new_obj(machine_pin_obj_t);
    pin->base = machine_pin_obj_template;
    pin->port = gpio_port_ptr;
    pin->pin = pin_index;
    
    return pin;
}

// constructor(drv_name, pin, ...)
mp_obj_t mp_pin_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 1, MP_OBJ_FUN_ARGS_MAX, true);

    machine_pin_obj_t *pin = pin_find(args[0]);

    if (n_args > 1 || n_kw > 0) {
        // pin mode given, so configure this GPIO
        mp_map_t kw_args;
        mp_map_init_fixed_table(&kw_args, n_kw, args + n_args);
        machine_pin_obj_init_helper(pin, n_args - 1, args + 1, &kw_args);
    }

    return (mp_obj_t)pin;
}

// fast method for getting/setting pin value
STATIC mp_obj_t machine_pin_call(mp_obj_t self_in, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 0, 1, false);
    machine_pin_obj_t *self = self_in;
    if (n_args == 0) {
        uint32_t pin_val = XMC_GPIO_GetInput(self->port, self->pin);
        return MP_OBJ_NEW_SMALL_INT(pin_val);
    } else {
        XMC_GPIO_SetOutputLevel(self->port, self->pin, mp_obj_is_true(args[0]) ? XMC_GPIO_OUTPUT_LEVEL_HIGH : XMC_GPIO_OUTPUT_LEVEL_LOW);
        return mp_const_none;
    }
}

// pin.init(mode, pull)
STATIC mp_obj_t machine_pin_obj_init(size_t n_args, const mp_obj_t *args, mp_map_t *kw_args) {
    return machine_pin_obj_init_helper(args[0], n_args - 1, args + 1, kw_args);
}
MP_DEFINE_CONST_FUN_OBJ_KW(machine_pin_init_obj, 1, machine_pin_obj_init);

// pin.value([value])
STATIC mp_obj_t machine_pin_value(size_t n_args, const mp_obj_t *args) {
    return machine_pin_call(args[0], n_args - 1, 0, args + 1);
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(machine_pin_value_obj, 1, 2, machine_pin_value);

STATIC mp_obj_t machine_pin_off(mp_obj_t self_in) {
    machine_pin_obj_t *self = self_in;
    (void)XMC_GPIO_SetOutputLevel(self->port, self->pin, XMC_GPIO_OUTPUT_LEVEL_LOW);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(machine_pin_off_obj, machine_pin_off);

STATIC mp_obj_t machine_pin_on(mp_obj_t self_in) {
    machine_pin_obj_t *self = self_in;
    (void)XMC_GPIO_SetOutputLevel(self->port, self->pin, XMC_GPIO_OUTPUT_LEVEL_HIGH);
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(machine_pin_on_obj, machine_pin_on);

STATIC mp_uint_t machine_pin_ioctl(mp_obj_t self_in, mp_uint_t request, uintptr_t arg, int *errcode) {
    (void)errcode;
    machine_pin_obj_t *self = self_in;

    switch (request) {
        case MP_PIN_READ: {
            uint32_t pin_val = XMC_GPIO_GetInput(self->port, self->pin);
            return pin_val;
        }
        case MP_PIN_WRITE: {
            XMC_GPIO_SetOutputLevel(self->port, self->pin, arg);
            return 0;
        }
    }
    return -1;
}

STATIC const mp_rom_map_elem_t machine_pin_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_init),    MP_ROM_PTR(&machine_pin_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_value),   MP_ROM_PTR(&machine_pin_value_obj) },
    { MP_ROM_QSTR(MP_QSTR_off),     MP_ROM_PTR(&machine_pin_off_obj) },
    { MP_ROM_QSTR(MP_QSTR_on),      MP_ROM_PTR(&machine_pin_on_obj) },

    // class constants
    { MP_ROM_QSTR(MP_QSTR_IN),        MP_ROM_INT(XMC_GPIO_MODE_INPUT_TRISTATE) },
    { MP_ROM_QSTR(MP_QSTR_OUT),       MP_ROM_INT(XMC_GPIO_MODE_OUTPUT_PUSH_PULL) },
    { MP_ROM_QSTR(MP_QSTR_OPEN_DRAIN), MP_ROM_INT(XMC_GPIO_MODE_OUTPUT_OPEN_DRAIN) },
    { MP_ROM_QSTR(MP_QSTR_PULL_UP),   MP_ROM_INT(XMC_GPIO_MODE_INPUT_PULL_UP) },
    { MP_ROM_QSTR(MP_QSTR_PULL_DOWN), MP_ROM_INT(XMC_GPIO_MODE_INPUT_PULL_DOWN) },
    { MP_ROM_QSTR(MP_QSTR_LOW_POWER), MP_ROM_INT(XMC_GPIO_OUTPUT_STRENGTH_WEAK) },
    { MP_ROM_QSTR(MP_QSTR_MED_POWER), MP_ROM_INT(XMC_GPIO_OUTPUT_STRENGTH_MEDIUM) },
    { MP_ROM_QSTR(MP_QSTR_HIGH_POWER), MP_ROM_INT(XMC_GPIO_OUTPUT_STRENGTH_STRONG_MEDIUM_EDGE) },
};

STATIC MP_DEFINE_CONST_DICT(machine_pin_locals_dict, machine_pin_locals_dict_table);

STATIC const mp_pin_p_t machine_pin_pin_p = {
    .ioctl = machine_pin_ioctl,
};

const mp_obj_type_t machine_pin_type = {
    { &mp_type_type },
    .name = MP_QSTR_Pin,
    .print = machine_pin_print,
    .make_new = mp_pin_make_new,
    .call = machine_pin_call,
    .protocol = &machine_pin_pin_p,
    .locals_dict = (mp_obj_t)&machine_pin_locals_dict,
};
