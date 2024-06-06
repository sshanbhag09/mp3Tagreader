#ifndef COMMON_H
#define COMMON_H


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef enum
{
    SUCCESS = 1,
    ERROR = -1
} Status;


Status Validate_inputs(char **argv);



//edit
typedef struct _TagData
{
    /* Source MP3 file Info */
    FILE * fptr_mp3;

	/* Temporary MP3 file Info */
    FILE * fptr_temp;

	/* Updated value Info passed in the Command Line */
    char frame_Id [5];
    char frame_Id_value [100];
    int frame_Id_size;
} TagData;
#endif
  


