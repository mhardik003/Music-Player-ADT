#include "song.h"
#ifndef MUSICPLAYER_H
#define MUSICPLAYER_H

typedef struct musicplayer *musicplayer_pointer;
//typedef music_player_queue queue_pointer;

struct musicplayer
{
    song_pointer queue;
    song_pointer curr_song;
    song_pointer temp_curr;
    int num_songs;
};

musicplayer_pointer createMusicPlayer();
int addSongToQueue (musicplayer_pointer, song_pointer);
int removeSongFromQueue(musicplayer_pointer, int);
int playSong(musicplayer_pointer);
song_pointer getCurrentSong(musicplayer_pointer);

#endif