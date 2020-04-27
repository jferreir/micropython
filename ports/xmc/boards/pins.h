#ifndef PINS_H
#define PINS_H

#define DIG_IN_OUT 0x01
#define DIG_IN     0x02
#define AN         0x04
#define DAC_OUT    0x08

#define GPIO_SET_ID(port, pin) (((port & 0xf) << 4) | (pin & 0xf))
#define GPIO_GET_PORT(id) ((id & 0xf0) >> 4)
#define GPIO_GET_PIN(id)  (id & 0x0f)

#if defined(XMC4700_F144x2048) || defined(XMC4700_F144x1024) || defined(XMC4700_F144x1536)
#include "xmc47_144_pins.h"
#endif

#ifndef P0_0_ATTR
#define P0_0_ATTR  0
#endif

#ifndef P0_1_ATTR
#define P0_1_ATTR  0
#endif

#ifndef P0_2_ATTR
#define P0_2_ATTR  0
#endif

#ifndef P0_3_ATTR
#define P0_3_ATTR  0
#endif

#ifndef P0_4_ATTR
#define P0_4_ATTR  0
#endif

#ifndef P0_5_ATTR
#define P0_5_ATTR  0
#endif

#ifndef P0_6_ATTR
#define P0_6_ATTR  0
#endif

#ifndef P0_7_ATTR
#define P0_7_ATTR  0
#endif

#ifndef P0_8_ATTR
#define P0_8_ATTR  0
#endif

#ifndef P0_9_ATTR
#define P0_9_ATTR  0
#endif

#ifndef P0_10_ATTR
#define P0_10_ATTR  0
#endif

#ifndef P0_11_ATTR
#define P0_11_ATTR  0
#endif

#ifndef P0_12_ATTR
#define P0_12_ATTR  0
#endif

#ifndef P0_13_ATTR
#define P0_13_ATTR  0
#endif

#ifndef P0_14_ATTR
#define P0_14_ATTR  0
#endif

#ifndef P0_15_ATTR
#define P0_15_ATTR  0
#endif

#ifndef P1_0_ATTR
#define P1_0_ATTR  0
#endif

#ifndef P1_1_ATTR
#define P1_1_ATTR  0
#endif

#ifndef P1_2_ATTR
#define P1_2_ATTR  0
#endif

#ifndef P1_3_ATTR
#define P1_3_ATTR  0
#endif

#ifndef P1_4_ATTR
#define P1_4_ATTR  0
#endif

#ifndef P1_5_ATTR
#define P1_5_ATTR  0
#endif

#ifndef P1_6_ATTR
#define P1_6_ATTR  0
#endif

#ifndef P1_7_ATTR
#define P1_7_ATTR  0
#endif

#ifndef P1_8_ATTR
#define P1_8_ATTR  0
#endif

#ifndef P1_9_ATTR
#define P1_9_ATTR  0
#endif

#ifndef P1_10_ATTR
#define P1_10_ATTR  0
#endif

#ifndef P1_11_ATTR
#define P1_11_ATTR  0
#endif

#ifndef P1_12_ATTR
#define P1_12_ATTR  0
#endif

#ifndef P1_13_ATTR
#define P1_13_ATTR  0
#endif

#ifndef P1_14_ATTR
#define P1_14_ATTR  0
#endif

#ifndef P1_15_ATTR
#define P1_15_ATTR  0
#endif

#ifndef P2_0_ATTR
#define P2_0_ATTR  0
#endif

#ifndef P2_1_ATTR
#define P2_1_ATTR  0
#endif

#ifndef P2_2_ATTR
#define P2_2_ATTR  0
#endif

#ifndef P2_3_ATTR
#define P2_3_ATTR  0
#endif

#ifndef P2_4_ATTR
#define P2_4_ATTR  0
#endif

#ifndef P2_5_ATTR
#define P2_5_ATTR  0
#endif

#ifndef P2_6_ATTR
#define P2_6_ATTR  0
#endif

#ifndef P2_7_ATTR
#define P2_7_ATTR  0
#endif

#ifndef P2_8_ATTR
#define P2_8_ATTR  0
#endif

#ifndef P2_9_ATTR
#define P2_9_ATTR  0
#endif

#ifndef P2_10_ATTR
#define P2_10_ATTR  0
#endif

#ifndef P2_11_ATTR
#define P2_11_ATTR  0
#endif

#ifndef P2_12_ATTR
#define P2_12_ATTR  0
#endif

#ifndef P2_13_ATTR
#define P2_13_ATTR  0
#endif

#ifndef P2_14_ATTR
#define P2_14_ATTR  0
#endif

#ifndef P2_15_ATTR
#define P2_15_ATTR  0
#endif

#ifndef P3_0_ATTR
#define P3_0_ATTR  0
#endif

#ifndef P3_1_ATTR
#define P3_1_ATTR  0
#endif

#ifndef P3_2_ATTR
#define P3_2_ATTR  0
#endif

#ifndef P3_3_ATTR
#define P3_3_ATTR  0
#endif

#ifndef P3_4_ATTR
#define P3_4_ATTR  0
#endif

#ifndef P3_5_ATTR
#define P3_5_ATTR  0
#endif

#ifndef P3_6_ATTR
#define P3_6_ATTR  0
#endif

#ifndef P3_7_ATTR
#define P3_7_ATTR  0
#endif

#ifndef P3_8_ATTR
#define P3_8_ATTR  0
#endif

#ifndef P3_9_ATTR
#define P3_9_ATTR  0
#endif

#ifndef P3_10_ATTR
#define P3_10_ATTR  0
#endif

#ifndef P3_11_ATTR
#define P3_11_ATTR  0
#endif

#ifndef P3_12_ATTR
#define P3_12_ATTR  0
#endif

#ifndef P3_13_ATTR
#define P3_13_ATTR  0
#endif

#ifndef P3_14_ATTR
#define P3_14_ATTR  0
#endif

#ifndef P3_15_ATTR
#define P3_15_ATTR  0
#endif

#ifndef P4_0_ATTR
#define P4_0_ATTR  0
#endif

#ifndef P4_1_ATTR
#define P4_1_ATTR  0
#endif

#ifndef P4_2_ATTR
#define P4_2_ATTR  0
#endif

#ifndef P4_3_ATTR
#define P4_3_ATTR  0
#endif

#ifndef P4_4_ATTR
#define P4_4_ATTR  0
#endif

#ifndef P4_5_ATTR
#define P4_5_ATTR  0
#endif

#ifndef P4_6_ATTR
#define P4_6_ATTR  0
#endif

#ifndef P4_7_ATTR
#define P4_7_ATTR  0
#endif

#ifndef P4_8_ATTR
#define P4_8_ATTR  0
#endif

#ifndef P4_9_ATTR
#define P4_9_ATTR  0
#endif

#ifndef P4_10_ATTR
#define P4_10_ATTR  0
#endif

#ifndef P4_11_ATTR
#define P4_11_ATTR  0
#endif

#ifndef P4_12_ATTR
#define P4_12_ATTR  0
#endif

#ifndef P4_13_ATTR
#define P4_13_ATTR  0
#endif

#ifndef P4_14_ATTR
#define P4_14_ATTR  0
#endif

#ifndef P4_15_ATTR
#define P4_15_ATTR  0
#endif

#ifndef P5_0_ATTR
#define P5_0_ATTR  0
#endif

#ifndef P5_1_ATTR
#define P5_1_ATTR  0
#endif

#ifndef P5_2_ATTR
#define P5_2_ATTR  0
#endif

#ifndef P5_3_ATTR
#define P5_3_ATTR  0
#endif

#ifndef P5_4_ATTR
#define P5_4_ATTR  0
#endif

#ifndef P5_5_ATTR
#define P5_5_ATTR  0
#endif

#ifndef P5_6_ATTR
#define P5_6_ATTR  0
#endif

#ifndef P5_7_ATTR
#define P5_7_ATTR  0
#endif

#ifndef P5_8_ATTR
#define P5_8_ATTR  0
#endif

#ifndef P5_9_ATTR
#define P5_9_ATTR  0
#endif

#ifndef P5_10_ATTR
#define P5_10_ATTR  0
#endif

#ifndef P5_11_ATTR
#define P5_11_ATTR  0
#endif

#ifndef P5_12_ATTR
#define P5_12_ATTR  0
#endif

#ifndef P5_13_ATTR
#define P5_13_ATTR  0
#endif

#ifndef P5_14_ATTR
#define P5_14_ATTR  0
#endif

#ifndef P5_15_ATTR
#define P5_15_ATTR  0
#endif

#ifndef P6_0_ATTR
#define P6_0_ATTR  0
#endif

#ifndef P6_1_ATTR
#define P6_1_ATTR  0
#endif

#ifndef P6_2_ATTR
#define P6_2_ATTR  0
#endif

#ifndef P6_3_ATTR
#define P6_3_ATTR  0
#endif

#ifndef P6_4_ATTR
#define P6_4_ATTR  0
#endif

#ifndef P6_5_ATTR
#define P6_5_ATTR  0
#endif

#ifndef P6_6_ATTR
#define P6_6_ATTR  0
#endif

#ifndef P6_7_ATTR
#define P6_7_ATTR  0
#endif

#ifndef P6_8_ATTR
#define P6_8_ATTR  0
#endif

#ifndef P6_9_ATTR
#define P6_9_ATTR  0
#endif

#ifndef P6_10_ATTR
#define P6_10_ATTR  0
#endif

#ifndef P6_11_ATTR
#define P6_11_ATTR  0
#endif

#ifndef P6_12_ATTR
#define P6_12_ATTR  0
#endif

#ifndef P6_13_ATTR
#define P6_13_ATTR  0
#endif

#ifndef P6_14_ATTR
#define P6_14_ATTR  0
#endif

#ifndef P6_15_ATTR
#define P6_15_ATTR  0
#endif

#ifndef P7_0_ATTR
#define P7_0_ATTR  0
#endif

#ifndef P7_1_ATTR
#define P7_1_ATTR  0
#endif

#ifndef P7_2_ATTR
#define P7_2_ATTR  0
#endif

#ifndef P7_3_ATTR
#define P7_3_ATTR  0
#endif

#ifndef P7_4_ATTR
#define P7_4_ATTR  0
#endif

#ifndef P7_5_ATTR
#define P7_5_ATTR  0
#endif

#ifndef P7_6_ATTR
#define P7_6_ATTR  0
#endif

#ifndef P7_7_ATTR
#define P7_7_ATTR  0
#endif

#ifndef P7_8_ATTR
#define P7_8_ATTR  0
#endif

#ifndef P7_9_ATTR
#define P7_9_ATTR  0
#endif

#ifndef P7_10_ATTR
#define P7_10_ATTR  0
#endif

#ifndef P7_11_ATTR
#define P7_11_ATTR  0
#endif

#ifndef P7_12_ATTR
#define P7_12_ATTR  0
#endif

#ifndef P7_13_ATTR
#define P7_13_ATTR  0
#endif

#ifndef P7_14_ATTR
#define P7_14_ATTR  0
#endif

#ifndef P7_15_ATTR
#define P7_15_ATTR  0
#endif

#ifndef P8_0_ATTR
#define P8_0_ATTR  0
#endif

#ifndef P8_1_ATTR
#define P8_1_ATTR  0
#endif

#ifndef P8_2_ATTR
#define P8_2_ATTR  0
#endif

#ifndef P8_3_ATTR
#define P8_3_ATTR  0
#endif

#ifndef P8_4_ATTR
#define P8_4_ATTR  0
#endif

#ifndef P8_5_ATTR
#define P8_5_ATTR  0
#endif

#ifndef P8_6_ATTR
#define P8_6_ATTR  0
#endif

#ifndef P8_7_ATTR
#define P8_7_ATTR  0
#endif

#ifndef P8_8_ATTR
#define P8_8_ATTR  0
#endif

#ifndef P8_9_ATTR
#define P8_9_ATTR  0
#endif

#ifndef P8_10_ATTR
#define P8_10_ATTR  0
#endif

#ifndef P8_11_ATTR
#define P8_11_ATTR  0
#endif

#ifndef P8_12_ATTR
#define P8_12_ATTR  0
#endif

#ifndef P8_13_ATTR
#define P8_13_ATTR  0
#endif

#ifndef P8_14_ATTR
#define P8_14_ATTR  0
#endif

#ifndef P8_15_ATTR
#define P8_15_ATTR  0
#endif

#ifndef P9_0_ATTR
#define P9_0_ATTR  0
#endif

#ifndef P9_1_ATTR
#define P9_1_ATTR  0
#endif

#ifndef P9_2_ATTR
#define P9_2_ATTR  0
#endif

#ifndef P9_3_ATTR
#define P9_3_ATTR  0
#endif

#ifndef P9_4_ATTR
#define P9_4_ATTR  0
#endif

#ifndef P9_5_ATTR
#define P9_5_ATTR  0
#endif

#ifndef P9_6_ATTR
#define P9_6_ATTR  0
#endif

#ifndef P9_7_ATTR
#define P9_7_ATTR  0
#endif

#ifndef P9_8_ATTR
#define P9_8_ATTR  0
#endif

#ifndef P9_9_ATTR
#define P9_9_ATTR  0
#endif

#ifndef P9_10_ATTR
#define P9_10_ATTR  0
#endif

#ifndef P9_11_ATTR
#define P9_11_ATTR  0
#endif

#ifndef P9_12_ATTR
#define P9_12_ATTR  0
#endif

#ifndef P9_13_ATTR
#define P9_13_ATTR  0
#endif

#ifndef P9_14_ATTR
#define P9_14_ATTR  0
#endif

#ifndef P9_15_ATTR
#define P9_15_ATTR  0
#endif

#ifndef P14_0_ATTR
#define P14_0_ATTR  0
#endif

#ifndef P14_1_ATTR
#define P14_1_ATTR  0
#endif

#ifndef P14_2_ATTR
#define P14_2_ATTR  0
#endif

#ifndef P14_3_ATTR
#define P14_3_ATTR  0
#endif

#ifndef P14_4_ATTR
#define P14_4_ATTR  0
#endif

#ifndef P14_5_ATTR
#define P14_5_ATTR  0
#endif

#ifndef P14_6_ATTR
#define P14_6_ATTR  0
#endif

#ifndef P14_7_ATTR
#define P14_7_ATTR  0
#endif

#ifndef P14_8_ATTR
#define P14_8_ATTR  0
#endif

#ifndef P14_9_ATTR
#define P14_9_ATTR  0
#endif

#ifndef P14_10_ATTR
#define P14_10_ATTR  0
#endif

#ifndef P14_11_ATTR
#define P14_11_ATTR  0
#endif

#ifndef P14_12_ATTR
#define P14_12_ATTR  0
#endif

#ifndef P14_13_ATTR
#define P14_13_ATTR  0
#endif

#ifndef P14_14_ATTR
#define P14_14_ATTR  0
#endif

#ifndef P14_15_ATTR
#define P14_15_ATTR  0
#endif

#ifndef P15_0_ATTR
#define P15_0_ATTR  0
#endif

#ifndef P15_1_ATTR
#define P15_1_ATTR  0
#endif

#ifndef P15_2_ATTR
#define P15_2_ATTR  0
#endif

#ifndef P15_3_ATTR
#define P15_3_ATTR  0
#endif

#ifndef P15_4_ATTR
#define P15_4_ATTR  0
#endif

#ifndef P15_5_ATTR
#define P15_5_ATTR  0
#endif

#ifndef P15_6_ATTR
#define P15_6_ATTR  0
#endif

#ifndef P15_7_ATTR
#define P15_7_ATTR  0
#endif

#ifndef P15_8_ATTR
#define P15_8_ATTR  0
#endif

#ifndef P15_9_ATTR
#define P15_9_ATTR  0
#endif

#ifndef P15_10_ATTR
#define P15_10_ATTR  0
#endif

#ifndef P15_11_ATTR
#define P15_11_ATTR  0
#endif

#ifndef P15_12_ATTR
#define P15_12_ATTR  0
#endif

#ifndef P15_13_ATTR
#define P15_13_ATTR  0
#endif

#ifndef P15_14_ATTR
#define P15_14_ATTR  0
#endif

#ifndef P15_15_ATTR
#define P15_15_ATTR  0
#endif

#endif