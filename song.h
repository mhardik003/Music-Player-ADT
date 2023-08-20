
#ifndef SONG_H
#define SONG_H

typedef struct song* song_pointer;

struct song
{
    char name[100];
    char artist[100];
    float duration;
    song_pointer next;
};

song_pointer makeSong(char*, char*, float);//creates a new song



#endif