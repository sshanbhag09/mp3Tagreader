#ifndef VIEW_H
#define VIEW_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct tag
{
	char frame_id [4];

    int track_number_size;
	char *track_number;

	char* title_tag;
    int title_tag_size;

    /* Artist Info */
    char* artist_tag;
    int artist_tag_size;

    /* Album Info */
    char* album_tag;
    int album_tag_size;

    /* Year of Release Info */
    char* year;
    int year_size;

    /* Content Type Info */
    char* content_type;
    int content_type_size;

    /* Comments Info */
    char* comments;
    int comment_size;
} mp3tag_info;

char ch;
Status get_and_display_data (const char* str_frame, const char* str_Id, char* frame_Id, int* tag_size, char* tag, FILE* fptr);
Status displayTags(mp3tag_info * mp3info,FILE *fp);
Status View_mp3(char **argv);


#endif

