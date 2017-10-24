#include<sys/wait.h>
#include<sys/types.h>
#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<string.h>

int main () {
	pid_t childid;
	int status;
	FILE *fp,*fp1;

	childid = fork();
	if (childid < 0) exit(EXIT_FAILURE);
	if (childid == 0)  {
		char *argv[4] = {"/bin/cp","dmesg.log","logku.txt",NULL};
		execv("/bin/cp",argv);
	}
	else {
		while ((wait(&status)) > 0);
		fp = fopen("/home/jwilyandi19/modul2/logku.txt","r");
		fp1 = fopen("/home/jwilyandi19/modul2/wlan0.log","w");
		char *line = NULL;
		size_t len = 0;
		ssize_t read;
		while((read = getline(&line,&len,fp)) != -1) {
		if(strstr(line,"wlan0")!=NULL) fprintf(fp1,"%s",line);
	}
	}
}
