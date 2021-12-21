#include "dirent.h"
#include <stdio.h>
#include <string.h>

int main()
{
	char data[300];
	

	char *ptr;
	FILE *file = fopen("/proc/version", "r");

	if(file == NULL)
	{
		printf("Cannot read version\nError!");
		return -1;
	}
	else
	{
		
		fgets(data, 200, file);
		ptr = strchr(data, '#');
		
		printf("Version : %s", ptr);
	}
	
	fclose(file);
	int flag = 0;
	FILE *file2 = fopen ("/etc/os-release", "r");
	if(file2 == NULL)
	{
		printf("Cannot read os-release\nError!");
		return -1;
	}
	else
	{
		do
		{
			fgets(data, 100, file2);
		
			ptr = strstr(data, "PRETTY_NAME");
			if(ptr!=0)
			{
				flag = 1;
			}
				
			
		}while(!feof(file2) && flag == 0);
	 	ptr = ptr + strlen("PRETTY_NAME=");
		printf("OS : %s", ptr);
	}
	fclose(file);
}
			

				
				
				
				

