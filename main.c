#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "musicplayer.h"
#include "song.h"

int main()
{
    musicplayer_pointer mpp;
    mpp = createMusicPlayer();
    song_pointer sp;
    int numSongs = 0;
    song_pointer *temp_songs_queue = (struct song **)malloc(1000 * sizeof(struct song *));
    while (1)
    {
        // printf("Enter your choice\n");
        char s[100];
        scanf("%s", s);
        if (strcmp("EXIT", s) == 0)
        {
            break;
        }
        else if (strcmp(s, "ADD") == 0 || strcmp (s, "make_song") == 0)
        {
            char name[100];
            char artist[100];
            float duration1;
            scanf("%s %s %f", name, artist, &duration1);
            sp = makeSong(name, artist, duration1);
            temp_songs_queue[numSongs++] = sp;
            printf("Song %s with artist %s and duration %f created\n", sp->name, sp->artist, sp->duration);
        }
        else if (strcmp(s, "INSERT") == 0 || strcmp(s, "add_queue") == 0)
        {
            char temp[100];
            scanf("%s", temp);
            int idx = -1;
            for (int a = 0; a < numSongs; a++)
            {
                if (strcmp(temp, temp_songs_queue[a]->name) == 0)
                    idx = a;
            }
            if (idx == -1)
            {
                printf("No song found with the name %s\n    ", temp);
                continue;
            }
            if (addSongToQueue(mpp, temp_songs_queue[idx]) == 1)
            {
                printf("%s added successfully\n", temp);
            }
            else
            {
                printf("%s couldn't be added to the music player\n", temp);
            }
        }
        else if (strcmp(s, "REMOVE") == 0 || strcmp(s, "remove_song") == 0)
        {
            int i;
            scanf("%d", &i);
            if (removeSongFromQueue(mpp, i))
            {
                printf("Song at index %d removed successfully\n", i);
            }
            else
            {
                printf("Song at index %d couldn't be removed\n", i);
            }
        }
        else if (strcmp(s, "PLAY") == 0 || strcmp(s, "play_song") == 0)
        {
            if (playSong(mpp))
                printf("Playing song\n");
            else
                printf("Couldn't play song\n");
                // printf("Mpp->curr_song from the main function name : %s", mpp->temp_curr->name);
        }
        else if (strcmp(s, "GET") == 0 || strcmp(s, "current_song") == 0)
        {
            song_pointer sp1;
            //sp1 = makeSong("zz", "zz", -1);
            sp1 = getCurrentSong(mpp);
            if (sp1 == NULL)
            {
                printf("No song playing\n");
            }
            else
            {
                printf("%s is playing right now\n", sp1->name);
            }
        }
        else
        {
            printf("Invalid command\n");
        }
    }
    return 0;
}