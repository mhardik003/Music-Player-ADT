#include "song.h"
#include <stdlib.h>
#include <string.h>
#include<stdio.h>
song_pointer makeSong(char name1[], char artist1[], float duration1)//creates a new song
{
    song_pointer sp;
    sp=(song_pointer)malloc(sizeof(struct song));
    strcpy(sp->name, name1);
    strcpy(sp->artist, artist1);
    sp->duration = duration1;
    sp->next = (song_pointer)malloc(sizeof(struct song));
    return sp;
}