#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

int lohan;
int kepiting;



int main () {
	pthread_t tid1,tid2;
	lohan = 100;
	kepiting = 100;
	char choose[12];
	
	pthread_create(&(tid1),NULL,&declohan,NULL);
	pthread_create(&(tid2),NULL,&deckepiting,NULL);

	while(1) {
	if(lohan<=0 || kepiting<=0 || lohan>100 || kepiting>100) {
		printf("Game Ends\n");
		break;
	}
	else {
		printf("Choose Lohan or Kepiting to be feed\n");
		printf("If you want to see their status, choose Status\n");
		scanf("%s",choose);		
		if(strcmp(choose,"Lohan")==0) {
			printf("Your Lohan's previous status: %d\n",lohan);			
			lohan = lohan + 10;
			printf("After feed, Lohan's status: %d\n",lohan);
		}
		else if (strcmp(choose,"Kepiting")==0) {
			printf("Your Kepiting's previous status: %d\n".kepiting);
			kepiting = kepiting + 10;
			printf("After feed, Kepiting's status: %d\n",kepiting);
		}
	}
	}
