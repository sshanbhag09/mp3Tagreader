/*#include "edit.h"


/*int get_tags_to_edit(char *argv[],TagEdit * tagedit)
{
	int idx;

	char *array[6] = {"TRCK","TIT2","TPE1","TALB","TYER","COMM","TCON"};
	
	
	for (idx = 0; idx < 6; idx++)
	{
		if (strncmp(, array[idx], strlen(array[idx])) == 0)
		{
			break;
		}
	}

	return idx+1;
}*/
/*
Status read_files_edit(TagEdit *tagedit)
{
    fseek (tagedit->fptr_mp3, 0L, SEEK_SET);
    fseek (tagedit->fptr_temp, 0L, SEEK_SET);

    char str [10];
    int count;
    count  = fread (str, 1, 10, tagedit->fptr_mp3);
    if (count < 10)
    {
        printf ("ERROR: Unable to read from the MP3 file.\n");
        return p_failure;
    }
    else
    {
        count = fwrite (str, 1, 10, tagedit->fptr_temp);
        if (count < 10)
        {
            printf ("ERROR: Unable to write on the MP3 file.\n");
            return p_failure;
        }
    }

}
void get_tagname(char *argv[],TagEdit *tagedit)
{
	if ((strncmp (argv [3], "-t", 2) == 0))
        {
            strncpy (tagedit->frame_Id, "TIT2", 5);
        }
        else if ((strncmp (argv [3], "-A", 2) == 0))
        {
            strncpy (tagedit->frame_Id, "TPE1", 5);
        }
        else if ((strncmp (argv [3], "-a", 2) == 0))
        {
            strncpy (tagedit->frame_Id, "TALB", 5);
        }
        else if ((strncmp (argv [3], "-y", 2) == 0))
        {
            strncpy (tagedit->frame_Id, "TYER", 5);
        }
        else if ((strncmp (argv [3], "-G", 2) == 0))
        {
            strncpy (tagedit->frame_Id, "TCON", 5);
        }
        else if ((strncmp (argv [3], "-c", 2) == 0))
        {
            strncpy (tagedit->frame_Id, "COMM", 5);
        }
	//printf("%s",tagedit->frame_Id);
}

Status open_edit_files(TagEdit *tagedit)
{
	if(tagedit -> fptr_mp3 == NULL)
	{
		perror("fopen");
		fprintf(stderr,"ERROR: unable to open the file %s\n",tagedit -> mp3_fname);

		return ERROR;
	}
	//printf("\nhi\n"); 
	return SUCCESS;
}

Status edit_tags(TagEdit *tagedit, char *argv[])
{
	int byte_read, idx;
	char buffer[4], ch;
	tagedit->fptr_mp3 = fopen(argv[2],"r");
	
	strcpy(tagedit -> mp3_fname, argv[2]);
	printf("%s", tagedit -> mp3_fname);

	open_edit_files(tagedit); //open file and check
	get_tagname(argv,tagedit); //get tagname
	read_files_edit(tagedit); //copy


}*/
