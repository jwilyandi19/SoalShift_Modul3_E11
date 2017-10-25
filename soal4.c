#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>

struct angka {
    int number;
};

void *faktorial(void *angka2)
{
    int ans=1;
    struct angka *my_angka = (struct angka*)angka2;

    int limit=my_angka->number

    for(int i=1; i<=limit; i++)
        ans*=i;

    printf("Hasil %d! = %d\n",limit,ans);
    free(angka2);
    return NULL;
}

int main () {
    pthread_t tid[100];
    int i=0;
    struct angka *angka2;
    while(1)
    {
        angka2 = malloc(sizeof(struct angka));
        scanf("%d",(*angka2).number);
        pthread_create(&(tid[i]),NULL,&faktorial,(void*) angka2);
        i++;
    }
}
