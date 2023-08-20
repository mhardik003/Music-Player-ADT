#include "song.h"
#include "musicplayer.h"
#ifndef USER_H
#define USER_H

typedef user* user_pointer;

struct User
{
    char *name_user[100];
    musicplayer_pointer user_music_player;
    song_pointer liked_songs_queue[100];
}user;

user_pointer createUser(char *);
int addSongToQueueUser(user_pointer, song_pointer);
int removeSongFromQueueUser (user_pointer, int);
int playSongUser(user_pointer);
song_pointer getCurrentSongUser (user_pointer);
int addLikedSong(user_pointer, song_pointer);
int removeLikedSong(user_pointer, song_pointer);
int userCompatibility(user_pointer, user_pointer);

#endif