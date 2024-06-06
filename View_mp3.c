#include "common.h"
#include "view.h"
Status get_and_display_data (const char* str_frame, const char* str_Id, char* frame_Id, int* tag_size, char* tag, FILE* fptr)

{
if ((strncmp (frame_Id, str_Id, 4)) == 0)	{
    int count = fread (tag_size, 4, 1, fptr);
    char* pos = (char*) tag_size;
    for (int i = 0; i < ((sizeof (int)) / 2); i++)
        {
            pos [i] = pos [i] ^ pos [(sizeof (int)) - i - 1];
            pos [(sizeof (int)) - i - 1] = pos [i] ^ pos [(sizeof (int)) - i - 1];
            pos [i] = pos [i] ^ pos [(sizeof (int)) - i - 1];
        }

        printf ("%sSize = %u.\n", str_frame, *tag_size);
        tag = (char*) malloc (((*tag_size) * sizeof (char)));		//To allocate the memory dynamically for storing the contents of the Frame ID.

        fseek (fptr, 3L, SEEK_CUR);		//1 byte of Flag is included in the size and 2 bytes of Flag are to be skipped. Total of 3 bytes of Flag shall be skipped.
                //printf ("Start: %ld.\n", ftell (fptr));

				//Suppose the Frame content size is 47, it includes 46 bytes of Frame ID content and 1 byte of Flag. So, we skip 3 bytes of Flag and read (size-1) for Frame ID content.
        count = fread (tag, 1, (*tag_size - 1), fptr);		//To read the (tag_size - 1) bytes of the Source MP3 file for the Frame ID content.
        if (count < (*tag_size - 1))						//Error Handling.
        {
            printf ("ERROR: Unable to read from the MP3 file.\n");
            return ERROR;
        }
        else
        {
            tag [*tag_size - 1] = '\0';						//To end the Frame ID content with '\0' as last character.
                    //printf ("End: %ld.\n", ftell (fptr));
            printf ("%-10s%s.\n", str_frame, tag);			//To display the Frame ID Contents.
        }
return SUCCESS;
}
return ERROR;
}
Status displayTags(mp3tag_info *mp3tag_info,FILE *fp)
{
    char *buff[7]={"TRCK","TIT2","TPE1","TALB","TYER","COMM","TCON"};
    int ret;
    //printf("Display Tags\n");
    //printf("%s",mp3tag_info->frame_id);
    for(int i=0;i<7;i++)
    {
        if(strncmp(buff[i],mp3tag_info->frame_id,4)==0)
        {
            
            switch(i)
            {
                case 0:
                ret = get_and_display_data ("Track: ", "TRCK", mp3tag_info->frame_id, &mp3tag_info->track_number_size, mp3tag_info->track_number,fp);
                       if (ret == ERROR)		//If the function doesn't display the data successfully, the process of Displaying will terminate.
                        {
                            printf ("ERROR: Track Frame ID Contents cannot be displayed.\n");
                            return ERROR;
                        }
                        break;
                case 1:ret = get_and_display_data ("Title: ", "TIT2", mp3tag_info->frame_id, &mp3tag_info->title_tag_size, mp3tag_info->title_tag, fp);
                       if (ret == ERROR)		//If the function doesn't display the data successfully, the process of Displaying will terminate.
                        {
                            printf ("ERROR: Title Frame ID Contents cannot be displayed.\n");
                            return ERROR;
                        }
                        break;
                case 2:ret = get_and_display_data ("Artist: ", "TPE1", mp3tag_info->frame_id, &mp3tag_info->artist_tag_size, mp3tag_info->artist_tag,fp);
                         if (ret == ERROR)		//If the function doesn't display the data successfully, the process of Displaying will terminate.
                        {
                            printf ("ERROR: Artist Frame ID Contents cannot be displayed.\n");
                            return ERROR;
                        }
                        break;
                case 3:ret = get_and_display_data ("Album: ", "TALB", mp3tag_info->frame_id, &mp3tag_info->album_tag_size, mp3tag_info->album_tag, fp);
                        if (ret == ERROR)		//If the function doesn't display the data successfully, the process of Displaying will terminate.
                        {
                            printf ("ERROR: album Frame ID Contents cannot be displayed.\n");
                            return ERROR;
                        }
                        break;
                case 4: ret = get_and_display_data ("Year: ", "TYER", mp3tag_info->frame_id, &mp3tag_info->year_size, mp3tag_info->year, fp);
                        if (ret == ERROR)		//If the function doesn't display the data successfully, the process of Displaying will terminate.
                        {
                            printf ("ERROR: Year Frame ID Contents cannot be displayed.\n");
                            return ERROR;
                        }
                        break;
                case 5:ret = get_and_display_data ("Comments: ", "COMM", mp3tag_info->frame_id, &mp3tag_info->comment_size, mp3tag_info->comments, fp);
                        if (ret == ERROR)		//If the function doesn't display the data successfully, the process of Displaying will terminate.
                        {
                            printf ("ERROR: Comments Frame ID Contents cannot be displayed.\n");
                            return ERROR;
                        }
                        break;
                case 6:ret = get_and_display_data ("Content: ", "TCON", mp3tag_info->frame_id, &mp3tag_info->content_type_size, mp3tag_info->content_type, fp);
                       if (ret == ERROR)		//If the function doesn't display the data successfully, the process of Displaying will terminate.
                        {
                            printf ("ERROR: Content Frame ID Contents cannot be displayed.\n");
                            return ERROR;
                        }
                        break;

            }
        }
    }
}
Status View_mp3(char **argv)
{
    FILE *fp;
    mp3tag_info mp3info; 
    int i;
    //Open file 
    //skip 10 bytes
    // start reading from one by one

	fp = fopen(argv[2], "r");
    
	fseek(fp,10,SEEK_SET);
	if(fp == NULL)
	{
        //printf("1");
		perror("fopen");
		exit(1);
	}

    while(feof(fp)==0)
    {
        //here take a character
        fread(&ch,sizeof(char),1,fp);
        if(ch=='C' || ch=='T')
        {
	    //printf("%ld POsition\n",ftell(fp));
            mp3info.frame_id[0]=ch;
            for(i=1;i<4;i++)
            {
                fread(&ch,sizeof(char),1,fp);
                mp3info.frame_id[i]=ch;
                
            }
	    mp3info.frame_id[i]='\0';
            //printf("%s",mp3info.frame_id);
            displayTags(&mp3info,fp);
        }
    }
}
    
   
