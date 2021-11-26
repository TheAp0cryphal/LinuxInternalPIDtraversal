#include "dirent.h"
#include <stdio.h>
#include <string.h>

int main()
{
	struct dirent *dirent;
	DIR *dir;
	dir = opendir("/proc");


	char ch[500];
	char path[100];
	char name[500];
	char format[100];
	

	if(dir == NULL)
	{
		printf("Cannot read proc\nError!");
		return -1;
	}
	else
	{
		printf("Success...\n");	
	}

	while((dirent = readdir(dir)))
	{
		
		if(!isdigit(*dirent->d_name))
			continue;
	
		strcpy(ch, dirent->d_name);
		printf("\nPID = %s\n", ch);		

		strcpy(path, "/proc/");
		strcat(path, ch);
		strcat(path, "/cmdline");

		FILE *file;
		file = fopen(path, "r");
		
	if(file == NULL)
	{
		printf("Cannot read cmdline\nError!");
		return -1;
	}
	else
	{	
					
			strcpy(name," ");		
			fgets(name, 100, file);
			int j = 0;
			for(int i = 0; i<strlen(name); i++,j++)
			{
				
				if(name[i]=='/')
				{
					
					j = -1;
				}
				else
				{
					
					format[j] = name[i];
				}
			}
			format[j] = 0;
					

			printf("Name= %s\n", format);
		

		

		fclose(file);
	}	
		

	}

	closedir(dir);
}





