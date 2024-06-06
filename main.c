#include "common.h"
#include "edit.h"
#include "view.h"


int main(int argc, char *argv[])
{
	//collect status
	int status = Validate_inputs(argv);
	printf("%d status",status);
	if(status == ERROR)
	{
		return 0;
	}
    
    //Check for viewing tags without error
	if(strcmp(argv[1],"-v") == 0)
	{
		if(status != ERROR)
		{
			printf("Sucess");
			View_mp3(argv);
			printf("Mp3 tags successfully viewed");
			return 0;
		}
	}

    //Check for editing tags without error
	if(strcmp(argv[1],"-e") == 0)
	{
		if(status != ERROR)
		{
			TagEdit tagedit;
			edit_tags(&tagedit,argv); 
			printf("Mp3 tags were successfully edited");
			return 0;
		}
	}
        
}

