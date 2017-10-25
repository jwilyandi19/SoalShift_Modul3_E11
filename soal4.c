#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>


void *faktorial(void *angka2)
{
    int limit = (int*)angka2;
	int ans = 1;

    for(int i=1; i<=limit; i++)
        ans*=i;

    printf("Hasil %d! = %d\n",limit,ans);
    return NULL;
}

int main (int n, char *x[]) {

    pthread_t tid[100];
    int i;
	int num;
	//printf("n: %d\n",n);
    for(i=1;i<n;i++)
    {       
	num = atoi(x[i]);
		
	pthread_create(&(tid[i]),NULL,&faktorial,(void*) num);
	pthread_join(tid[i],NULL);
    	//printf("trad %d\n",err);
     }
}
