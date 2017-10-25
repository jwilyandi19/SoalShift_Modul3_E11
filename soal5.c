#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

struct kata {
    char huruf[50];
};

void *searchnovel(void *kata2)
{
    char x[50];
    int ans=0;
    struct kata *my_kata = (struct kata*)kata2;
    //printf("cok %s",my_kata->huruf);
    FILE *fp;
    fp = fopen("/home/farras/SoalShift_Modul3_E11/Novel.txt","r");
    while (fscanf(fp,"%s", x) == 1) {
	//printf("%s",x);
        if(strstr(x,my_kata->huruf)!=NULL)ans++;
    }

    printf("%s : %d\n",my_kata->huruf,ans);
    free(kata2);
    return NULL;
}

int main () {

    char temp[50];
    pthread_t tid[100];
    int i=0;
    struct kata *kata2;
    while(1)
    {
        kata2 = malloc(sizeof(struct kata));
        scanf("%s",(*kata2).huruf);
        pthread_create(&(tid[i]),NULL,&searchnovel,(void*) kata2);
        i++;
    }
}
