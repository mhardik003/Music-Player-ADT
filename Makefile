make all:
	gcc main.c musicplayer.c song.c -o musicplayer.out
	#gcc 3/main2.c 3/musicplayer.c 3/song.c 3/user.c -o q3b.out

clean:
	rm -r *.out