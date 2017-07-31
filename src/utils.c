#include "app.h"
#include "utils.h"

u8 get_pad_id(u8 x, u8 y) {
    return ((8 - y) * 10) + (1 + x);
}

bool is_pad(u8 pad_id) {
    (pad_id > 0) && (pad_id % 10 != 0) && ((pad_id + 1) % 10 != 0);
}

u8 get_row_from_pad_id(u8 pad_id) {
    return 8 - pad_id / 10;
}

u8 get_column_from_pad_id(u8 pad_id) {
    return pad_id % 10 - 1;
}
