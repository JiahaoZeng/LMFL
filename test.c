/**
** sort.c - An example of the LMFL DATA type.
** Copyright (c) 2023 JiahaoZeng.
**/

#include "LMFL1.h"

#ifndef SONG_TYPE
#define SONG_TYPE
typedef struct{
    char* name;
    unsigned hotness;
}
song;

bool compare_song_hotness(DATA d1, DATA d2){
    song s1, s2;
    LMFL_DATA_EXPORT(d1, s1);
    LMFL_DATA_EXPORT(d2, s2);
    return s1.hotness > s2.hotness;
}

void print_songs_name(song* array, unsigned length){
    printf("Songs: ");
    for(unsigned i = 0; i < length; i++){
        printf("\"%s\" ", array[i].name);
    }
    printf(".\n");
}
#endif /*SONG_TYPE*/

#ifndef SINGER_TYPE
#define SINGER_TYPE
typedef struct{
    char* name;
    unsigned hotness;
}
singer;

bool compare_singer_hotness(DATA d1, DATA d2){
    singer s1, s2;
    LMFL_DATA_EXPORT(d1, s1);
    LMFL_DATA_EXPORT(d2, s2);
    return s1.hotness > s2.hotness;
}

void print_singers_name(singer* array, unsigned length){
    printf("Singers: ");
    for(unsigned i = 0; i < length; i++){
        printf("\"%s\" ", array[i].name);
    }
    printf(".\n");
}
#endif /*SINGER_TYPE*/

int main(){
    LMFL;

    // sort song
    song songs[3];
    songs[0].hotness = 10;
    songs[0].name = "Awaiting on you all";
    songs[1].hotness = 5;
    songs[1].name = "Beware Of Darkness";
    songs[2].hotness = 20;
    songs[2].name = "Run Of The Mill";

    _LMFL_ALGO_sort( songs, sizeof(song), compare_song_hotness, 3);
    print_songs_name( songs, 3);

    // sort singer
    singer singers[4];
    singers[0].hotness = 7;
    singers[0].name = "Paul McCartney";
    singers[1].hotness = 2;
    singers[1].name = "Ringo Starr";
    singers[2].hotness = 6;
    singers[2].name = "John Lennon";
    singers[3].hotness = 100;
    singers[3].name = "George Harrison";

    _LMFL_ALGO_sort( singers, sizeof(singer), compare_singer_hotness, 4);
    print_singers_name( singers, 4);

    return 0;
}