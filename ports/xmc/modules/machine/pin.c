/*
 * This file is part of the MicroPython project, http://micropython.org/
 *
 * The MIT License (MIT)
 *
 * Copyright (c) 2013, 2014 Damien P. George
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
#include <stdint.h>
#include <string.h>

#include "py/runtime.h"
#include "py/mphal.h"

/*
  Access the pin peripheral (GPIO pin) associated with the given id. 
  If additional arguments are given in the constructor then they are used to initialise the pin. 
  Any settings that are not specified will remain in their previous state.

    The arguments are:
        - id is mandatory and can be an arbitrary object. 
            Among possible value types are: int (an internal Pin identifier), str (a Pin name), and tuple (pair of [port, pin]).
        - mode specifies the pin mode, which can be one of:
            Pin.IN - Pin is configured for input. If viewed as an output the pin is in high-impedance state.
            Pin.OUT - Pin is configured for (normal) output.
            Pin.OPEN_DRAIN - Pin is configured for open-drain output. Open-drain output works in the following way: if the output value is set to 0 the pin is active at a low level; if the output value is 1 the pin is in a high-impedance state. Not all ports implement this mode, or some might only on certain pins.
            Pin.ALT - Pin is configured to perform an alternative function, which is port specific. For a pin configured in such a way any other Pin methods (except Pin.init()) are not applicable (calling them will lead to undefined, or a hardware-specific, result). Not all ports implement this mode.
            Pin.ALT_OPEN_DRAIN - The Same as Pin.ALT, but the pin is configured as open-drain. Not all ports implement this mode.
        - pull specifies if the pin has a (weak) pull resistor attached, and can be one of:
            None - No pull up or down resistor.
            Pin.PULL_UP - Pull up resistor enabled.
            Pin.PULL_DOWN - Pull down resistor enabled.
        - value is valid only for Pin.OUT and Pin.OPEN_DRAIN modes and specifies initial output pin value if given, otherwise the state of the pin peripheral remains unchanged.
        - drive specifies the output power of the pin and can be one of: Pin.LOW_POWER, Pin.MED_POWER or Pin.HIGH_POWER. The actual current driving capabilities are port dependent. Not all ports implement this argument.
        - alt specifies an alternate function for the pin and the values it can take are port dependent. This argument is valid only for Pin.ALT and Pin.ALT_OPEN_DRAIN modes. It may be used when a pin supports more than one alternate function. If only one pin alternate function is supported the this argument is not required. Not all ports implement this argument.

    As specified above, the Pin class allows to set an alternate function for a particular pin, but it does not specify any further operations on such a pin. 
    Pins configured in alternate-function mode are usually not used as GPIO but are instead driven by other hardware peripherals. 
    The only operation supported on such a pin is re-initialising, by calling the constructor or Pin.init() method. 
    If a pin that is configured in alternate-function mode is re-initialised with Pin.IN, Pin.OUT, or Pin.OPEN_DRAIN, the alternate function will be removed from the pin.
*/

STATIC mp_obj_t pin_obj_init(size_t n_args, const mp_obj_t *args, mp_map_t *kw_args) {
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(pin_init_obj, 1, pin_obj_init);

/*
    This method allows to set and get the value of the pin, depending on whether the argument x is supplied or not.
    
    If the argument is omitted then this method gets the digital logic level of the pin, returning 0 or 1 corresponding to low and high voltage signals respectively. The behaviour of this method depends on the mode of the pin:

            Pin.IN - The method returns the actual input value currently present on the pin.
            Pin.OUT - The behaviour and return value of the method is undefined.
            Pin.OPEN_DRAIN - If the pin is in state ‘0’ then the behaviour and return value of the method is undefined. Otherwise, if the pin is in state ‘1’, the method returns the actual input value currently present on the pin.

    If the argument is supplied then this method sets the digital logic level of the pin. The argument x can be anything that converts to a boolean. If it converts to True, the pin is set to state ‘1’, otherwise it is set to state ‘0’. The behaviour of this method depends on the mode of the pin:

            Pin.IN - The value is stored in the output buffer for the pin. The pin state does not change, it remains in the high-impedance state. The stored value will become active on the pin as soon as it is changed to Pin.OUT or Pin.OPEN_DRAIN mode.
            Pin.OUT - The output buffer is set to the given value immediately.
            Pin.OPEN_DRAIN - If the value is ‘0’ the pin is set to a low voltage state. Otherwise the pin is set to high-impedance state.

    When setting the value this method returns None.
*/
STATIC mp_obj_t pin_value(size_t n_args, const mp_obj_t *args) {
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_VAR_BETWEEN(pin_value_obj, 1, 2, pin_value);

/*
    Set pin to “0” output level.
*/
STATIC mp_obj_t pin_off(mp_obj_t self_in) {
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(pin_off_obj, pin_off);

/*
    Set pin to “0” output level.
*/
STATIC mp_obj_t pin_on(mp_obj_t self_in) {
    return mp_const_none;
}
STATIC MP_DEFINE_CONST_FUN_OBJ_1(pin_on_obj, pin_on);

STATIC const mp_rom_map_elem_t pin_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_init),    MP_ROM_PTR(&pin_init_obj) },
    { MP_ROM_QSTR(MP_QSTR_value),   MP_ROM_PTR(&pin_value_obj) },
    { MP_ROM_QSTR(MP_QSTR_off),     MP_ROM_PTR(&pin_off_obj) },
    { MP_ROM_QSTR(MP_QSTR_on),      MP_ROM_PTR(&pin_on_obj) },
};

STATIC MP_DEFINE_CONST_DICT(pin_locals_dict, pin_locals_dict_table);

STATIC void pin_print(const mp_print_t *print, mp_obj_t self_in, mp_print_kind_t kind) 
{
}

/// \classmethod \constructor(id, ...)
/// Create a new Pin object associated with the id.  If additional arguments are given,
/// they are used to initialise the pin.  See `init`.
mp_obj_t mp_pin_make_new(const mp_obj_type_t *type, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 1, MP_OBJ_FUN_ARGS_MAX, true);

    // Run an argument through the mapper and return the result.
    const pin_obj_t *pin = pin_find(args[0]);

    if (n_args > 1 || n_kw > 0) {
        // pin mode given, so configure this GPIO
        mp_map_t kw_args;
        mp_map_init_fixed_table(&kw_args, n_kw, args + n_args);
        pin_obj_init_helper(pin, n_args - 1, args + 1, &kw_args);
    }

    return MP_OBJ_FROM_PTR(pin);
}

// fast method for getting/setting pin value
STATIC mp_obj_t pin_call(mp_obj_t self_in, size_t n_args, size_t n_kw, const mp_obj_t *args) {
    mp_arg_check_num(n_args, n_kw, 0, 1, false);
    pin_obj_t *self = MP_OBJ_TO_PTR(self_in);
    if (n_args == 0) {
        // get pin
        return MP_OBJ_NEW_SMALL_INT(mp_hal_pin_read(self));
    } else {
        // set pin
        mp_hal_pin_write(self, mp_obj_is_true(args[0]));
        return mp_const_none;
    }
}

const mp_obj_type_t machine_pin_class = {
    { &mp_type_type },
    .name = MP_QSTR_Pin,
    .print = pin_print,
    .make_new = mp_pin_make_new,
    .call = pin_call,
    .locals_dict = (mp_obj_dict_t*)&pin_locals_dict,
};
