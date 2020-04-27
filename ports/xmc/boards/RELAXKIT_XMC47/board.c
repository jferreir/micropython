#include "py/obj.h"

#include "pins.h"

STATIC const mp_rom_map_elem_t pin_board_pins_locals_dict_table[] = {
  { MP_ROM_QSTR(MP_QSTR_LED1), MP_ROM_INT(GPIO_SET_ID(5, 9)) },
  { MP_ROM_QSTR(MP_QSTR_LED2), MP_ROM_INT(GPIO_SET_ID(5, 8)) },
  { MP_ROM_QSTR(MP_QSTR_BUTTON1), MP_ROM_INT(GPIO_SET_ID(15, 13)) },
  { MP_ROM_QSTR(MP_QSTR_BUTTON2), MP_ROM_INT(GPIO_SET_ID(15, 12)) },
};
MP_DEFINE_CONST_DICT(pin_board_pins_locals_dict, pin_board_pins_locals_dict_table);
