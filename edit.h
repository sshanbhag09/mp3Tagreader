#ifndef  EDIT_H
#define EDIT_H

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "common.h"

typedef struct _EditInfo
{
	FILE *fptr_mp3;
	
	FILE *tmp; 
	char mp3_fname[32];
	
	char frame_Id[4];
	
	int album_name_size;
	char *album_name;

	int singer_name_size;
	char *singer_name;

	int song_name_size;
	char *song_name;

	int album_year_size;
	char *album_year;


	int track_number_size;
	char *track_number;

	int album_art_size;
	char *album_art_name;

	int composer_name_size;
	char *composer_name;

	char edit_tags[5];
}TagEdit;


Status open_edit_files(TagEdit *tagedit);

void get_tagname(char *argv[],TagEdit *tagedit);
// Calculate the size of file tags
Status get_edit_size_tag(FILE *fptr);

Status read_files_edit(TagEdit *tagedit)

// Get tags to be editted
int get_tags_to_edit(char *argv[]);

// Get the options for tags to be editted
Status get_options(char *argv[], int argc, TagEdit *tagedit);

// Copy the tags from file
Status copy_tag_names(TagEdit *tagedit);

// Edit tags main function
Status edit_tags(TagEdit *tagedit, char *argv[]);

#endif
