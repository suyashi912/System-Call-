/* Name: Suyashi Singhal
   Roll_Number: 2019478 */
#include <stdio.h>
#include <string.h>
#include <sys/syscall.h>
#include <unistd.h>
#include <sys/types.h>
#include <errno.h>
#include <stdlib.h>

#define sh_task_info 548
extern int errno; 

int main()
{

	int pid ; 
	char file[256], cwd[256]; 
	printf("Enter pid: "); 
	scanf("%d", &pid);
	if(getcwd(cwd, sizeof(cwd))==NULL)
	{
		printf("Error: %s\n", strerror(errno));
		return 0; 
	}
	cwd[strlen(cwd)] = '\0'; 
	printf("Enter file name : ");
	scanf("%s", file); 
	strcat(cwd, "/"); 
	strcat(cwd, file); 
	
	if(pid<0)
	{
		printf("Process pid cannot be negative\n");
		long int t = syscall(sh_task_info, pid, cwd); 
		printf("System call sys_sh_task_info returned %ld\n", t);
		if(t != 0)
		{
			printf("Error : %s\n", strerror(errno));
		} 
	}
	else
	{
		long int t = syscall(sh_task_info, pid, cwd); 
		printf("System call sys_sh_task_info returned %ld\n", t);
		if(t != 0)
		{
			printf("Error : %s\n", strerror(errno));
		}

	}
        
         return 0;
}

