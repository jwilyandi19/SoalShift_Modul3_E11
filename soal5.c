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

    FILE *fp;
    fp = fopen("/home/farras/modul3/salin1.txt","r");


    while (fscanf(f, " %s", x) == 1) {
        if(strcmp(x,my_kata)==0)ans++;
    }

    printf("%d\n",ans);
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
        scanf("%s",temp);
        kata2 = malloc(sizeof(struct kata));
        (*kata).huruf = temp;
        pthread_create(&(tid[i]),NULL,&searchnovel,(void*) kata2);
        i++;
    }
}
