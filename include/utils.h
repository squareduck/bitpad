#ifndef UTILS_H
#define UTILS_H

// ID numbers for control buttons on the perimeter
#define BTN_UP    91
#define BTN_DOWN  92
#define BTN_LEFT  93
#define BTN_RIGHT 94

u8 get_pad_id(u8, u8);
bool is_pad(u8);
u8 get_row_from_pad_id(u8);
u8 get_column_from_pad_id(u8);

#endif
