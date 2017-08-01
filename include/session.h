#ifndef SESSION_H
#define SESSION_H

#define TRACKS_LIMIT 32
#define TRACK_CLIPS_LIMIT 16
#define TRACKS_OFFSET_LIMIT TRACKS_LIMIT - 8
#define TRACK_CLIPS_OFFSET_LIMIT TRACK_CLIPS_LIMIT - 8

// Session clip
typedef struct SessionClip {
    bool is_present;
} SessionClip;

typedef struct SessionTrack {
    u8 r;
    u8 g;
    u8 b;
    u8 active_clip;
} SessionTrack;

void init_session();

void move_session_view_up();
void move_session_view_down();
void move_session_view_left();
void move_session_view_right();

void create_session_clip(u8, u8);

void draw_session();
void draw_session_clips();
void draw_session_arrows();

#endif
