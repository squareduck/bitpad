#include "app.h"
#include "utils.h"
#include "session.h"

static SessionClip clips[TRACKS_LIMIT][TRACK_CLIPS_LIMIT];
static SessionClip cclips[TRACKS_LIMIT][TRACK_CLIPS_LIMIT];
static SessionClip ccclips[TRACKS_LIMIT][TRACK_CLIPS_LIMIT];
static SessionTrack tracks[TRACKS_LIMIT];
static u8 view_offset_x = 0;
static u8 view_offset_y = 0;

void init_session() {
    draw_session_clips();

    // Randomize track colors
    for (u8 i = 0; i < TRACKS_LIMIT; i++) {
        tracks[i].r = rand(255);
        tracks[i].g = rand(255);
        tracks[i].b = rand(255);
    }
}

// ----------------------------------------------------------------------------
// Navigation
// ----------------------------------------------------------------------------

void move_session_view_up() {
    if (view_offset_y > 0) {
        view_offset_y = view_offset_y - 1;
    }
}

void move_session_view_down() {
    if (view_offset_y < TRACK_CLIPS_OFFSET_LIMIT) {
        view_offset_y = view_offset_y + 1;
    }
}

void move_session_view_left() {
    if (view_offset_x > 0) {
        view_offset_x = view_offset_x - 1;
    }
}

void move_session_view_right() {
    if (view_offset_x < TRACKS_OFFSET_LIMIT) {
        view_offset_x = view_offset_x + 1;
    }
}

// ----------------------------------------------------------------------------
// Manipulation
// ----------------------------------------------------------------------------

void create_session_clip(u8 x, u8 y) {
    clips[x + view_offset_x][y + view_offset_y].is_present = true;
}

// ----------------------------------------------------------------------------
// Drawing
// ----------------------------------------------------------------------------

void draw_session() {
    draw_session_clips();
    draw_session_arrows();
}

void draw_session_clips() {
    for (int x = 0; x < 8; x++) {
        for (int y = 0; y < 8; y++) {
            u8 track_id = x + view_offset_x;
            u8 clip_id = y + view_offset_y;
            SessionClip clip = clips[track_id][clip_id];
            SessionTrack track = tracks[track_id];
            if (clip.is_present == true) {
                // hal_plot_led(TYPEPAD, get_pad_id(x, y), 200, 150, 150);
                hal_plot_led(TYPEPAD, get_pad_id(x, y), track.r, track.g, track.b);
            } else {
                hal_plot_led(TYPEPAD, get_pad_id(x, y), 0, 0, 0);
            }
        }
    }
}

void draw_session_arrows() {
    if (view_offset_y > 0) {
        hal_plot_led(TYPEPAD, BTN_UP, 255, 255, 255);
    } else {
        hal_plot_led(TYPEPAD, BTN_UP, 0, 0, 0);
    }

    if (view_offset_y < TRACK_CLIPS_OFFSET_LIMIT) {
        hal_plot_led(TYPEPAD, BTN_DOWN, 255, 255, 255);
    } else {
        hal_plot_led(TYPEPAD, BTN_DOWN, 0, 0, 0);
    }

    if (view_offset_x > 0) {
        hal_plot_led(TYPEPAD, BTN_LEFT, 255, 255, 255);
    } else {
        hal_plot_led(TYPEPAD, BTN_LEFT, 0, 0, 0);
    }

    if (view_offset_x < TRACKS_OFFSET_LIMIT) {
        hal_plot_led(TYPEPAD, BTN_RIGHT, 255, 255, 255);
    } else {
        hal_plot_led(TYPEPAD, BTN_RIGHT, 0, 0, 0);
    }
}
