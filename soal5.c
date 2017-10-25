#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

void *searchnovel(void *arg)
{
	//printf("casn\n");
    char x[50];
    int ans=0;
	char find[50];
	
    strcpy(find,arg);
	//printf("String Found: %s\n",find);
    FILE *fp;
    fp = fopen("Novel.txt","r");
    while (fscanf(fp,"%s",x) == 1) {
	//printf("%s",x);
        if(strstr(x,find)!=NULL)ans++;
    }

    printf("%s : %d\n",find,ans);
    return NULL;
}

int main (int n, char *x[]) {

    pthread_t tid[100];
    int i;
	//printf("n: %d\n",n);
    for(i=1;i<n;i++)
    {       
	//printf("hai %s\n",x[i]);
		
	pthread_create(&(tid[i]),NULL,&searchnovel,(void*) x[i]);
    	//printf("trad %d\n",err);
     }
	for(i=1; i<n; i++) pthread_join(tid[i],NULL);
}
