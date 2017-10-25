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
int bet;
int picked;
int stat;
int guess[5];

int status_returner() {
	if(score1==10 || score2==10 || have1==0 || have2==0) return 3;
}

void *play1 (void *arg) {
	
	while(1) {
		printf("%s's turn, your score: %d\n",player1,score1);
		printf("Let's pick\n");
		stat = 0;
		scanf("%d",&bet);

		while(bet--) {
			
			scanf("%d",&picked);
			if(hole1[picked]==0) have1 = have1-1;
			hole1[picked] = 1;
		}
		stat = 1;
		while(stat==1 || stat==3) {
			if(stat==3) return NULL;
		}
		printf("%s's turn, let's guess\n",player1);

		for(int i=0; i<4; i++) scanf("%d",&guess[i]);

		for(int i=0; i<4; i++) {
		
		if(hole2[guess[i]]==0) {
			printf("%s: +1\n",player1);
			score1++;
		}
		else {
			printf("%s: +1\n",player2);
			score2++;
		}

		if(status_returner()==3) {
			stat = 3;
			return NULL;
		}
		}
	}
}
		
void *play2 (void *arg) {
	
	while(1) {
		stat = 0;

		while(stat==0 || stat==3) {
			if(stat==3) return NULL;
		}
		printf("%s's turn, let's guess\n",player2);

		for(int i=0; i<4; i++) scanf("%d",&guess[i]);
		for(int i=0; i<4; i++) {

		if(hole1[guess[i]]==0) {
			printf("%s: +1\n",player2);
			score2++;
		}
		else {
			printf("%s: +1\n",player1);
			score1++;
		}

		if(status_returner()==3) {
			stat = 3;
			return NULL;
		}
		}
		printf("%s's turn, your score: %d\n",player2,score2);
		printf("Let's pick\n");

		scanf("%d",&bet);

		while(bet--) {
			
			scanf("%d",&picked);
			if(hole2[picked]==0) have2 = have2-1;
			hole2[picked] = 1;
		}
		stat = 2;
	}
}			


int main () {
	printf("You are player 1, input your name\n");
	scanf("%s",player1);
	printf("You are player 2, input your name\n");
	scanf("%s",player2);

	for(int i=0; i<16; i++) {
		hole1[i] = 0;
		hole2[i] = 0;
	}

	pthread_create(&(tid1),NULL,&play1,NULL);
	pthread_create(&(tid2),NULL,&play2,NULL);

	pthread_join(tid1,NULL);
	pthread_join(tid2,NULL);

	while(stat!=3) {
		printf("Game over\n");
		printf("%s's score: %d\n",player1,score1);
		printf("%s's score: %d\n",player2,score2);
		if(score1>score2) printf("%s wins\n",player1);
		else printf("%s wins\n",player2);
	}
}
