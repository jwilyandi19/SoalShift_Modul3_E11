#include<stdio.h>
#include<string.h>
#include<unistd.h>
#include<pthread.h>
#include<stdlib.h>
char player1[20];
char player2[20];
int hole1[17];
int hole2[17];
pthread_t tid1;
pthread_t tid2;
int score1=0,score2=0,have1=16,have2=16;	


int main () {
	printf("You are player 1, input your name\n");
	scanf("%s",player1);
	printf("You are player 2, input your name\n");
	scanf("%s",player2);

	for(int i=0; i<16; i++) {
		hole1[i] = 0;
		hole2[i] = 0;
	}
}
