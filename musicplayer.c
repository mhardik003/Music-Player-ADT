#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "musicplayer.h"
#include "song.h"

musicplayer_pointer createMusicPlayer()
{
    musicplayer_pointer mpp;
    mpp = (musicplayer_pointer)malloc(sizeof(struct musicplayer));
    mpp->queue = (song_pointer)malloc(sizeof(struct song));
    mpp->curr_song = (song_pointer)malloc(sizeof(struct song));
    mpp->queue = NULL;
    mpp->curr_song = NULL;
    mpp->num_songs = 0;
}
int addSongToQueue(musicplayer_pointer mpp, song_pointer sp)
{
    if (mpp->num_songs == 0)
    {
        mpp->queue = sp;
        mpp->curr_song = sp;
        mpp->temp_curr=sp;

        // printf("Name : %s\nArtist : %s\nDuration : %lf \n", sp->name, sp->artist, sp->duration);
    }
    else
    {
        // printf("Name : %s\nArtist : %s\nDuration : %lf \n", sp->name, sp->artist, sp->duration);
        mpp->queue->next = sp;
        mpp->queue = sp;
    }
   // printf("Mpp currsong from add to queue  is : %s \n", mpp->curr_song->name);
    mpp->num_songs++;
    return 1;
}
int removeSongFromQueue(musicplayer_pointer mpp, int i)
{
    if (i >= mpp->num_songs)
    {
        return 0;
    }
    if (i == 0)
    {
        song_pointer sp;
        sp = mpp->curr_song->next;
        
        mpp->temp_curr=mpp->curr_song;
       // printf("From remove song : curr_song : %s temp_curr : %s\n", mpp->curr_song->name, mpp->temp_curr->name);
       // free(mpp->curr_song);
       // printf("From remove song : curr_song : %s temp_curr : %s\n", mpp->curr_song->name, mpp->temp_curr->name);
        mpp->curr_song=sp;
        //free(mpp->curr_song);

        mpp->num_songs--;
        return 1;
    }
    if (i == (mpp->num_songs - 1))
    {
        i--;
        song_pointer sp = mpp->queue;
        while (i--)
        {
            sp = sp->next;
        }
        mpp->curr_song = sp;
        free(sp->next);
        mpp->num_songs--;
        return 1;
    }
    song_pointer sp = mpp->queue;
    while (i--)
    {
        sp = sp->next;
    }
    sp->next = sp->next->next;
    free(sp->next);
    mpp->num_songs--;

    return 1;
}
song_pointer getCurrentSong(musicplayer_pointer mpp)
{
    assert(mpp->num_songs >= 0);
    return mpp->temp_curr;
}
int playSong(musicplayer_pointer mpp)
{
    if (mpp->num_songs <= 0)
    {
        return 0;
    }
    //free(mpp->curr_song);
    mpp->temp_curr=mpp->curr_song;
    //printf("Mpp->currsong->name from the play Song function name : %s\n", mpp->temp_curr->name);
    // printf("Name : %s\nArtist : %s\nDuration : %lf\n", sp->name, sp->artist, sp->duration);
    removeSongFromQueue(mpp, 0);
    return 1;
}
