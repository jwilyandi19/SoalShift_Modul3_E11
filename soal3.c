#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<pthread.h>
#include<string.h>

int lohan;
int kepiting;

void *declohan (void *arg) {
	while(1) {
	sleep(10);
	lohan = lohan - 15;
	if(lohan<=0 || kepiting<=0 || lohan>100 || kepiting>100) {
		printf("\nGame Over\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("\nYour Lohan's status has been decreased by 15\n");
	}
	}
}

void *deckepiting (void *arg) {
	while(1) {
	sleep(20);
	kepiting = kepiting - 10;
	if(lohan<=0 || kepiting<=0 || lohan>100 || kepiting>100) {
		printf("\nGame Over\n");
		exit(EXIT_FAILURE);
	}
	else {
		printf("\nYour Kepiting's status has been decreased by 10\n");
	}
	}
}	


int main () {
	pthread_t tid1,tid2;
	lohan = 100;
	kepiting = 100;
	char choose[12];
	
	pthread_create(&(tid1),NULL,&declohan,NULL);
	pthread_create(&(tid2),NULL,&deckepiting,NULL);

	while(1) {
	if(lohan<=0 || kepiting<=0 || lohan>100 || kepiting>100) {
		printf("\nGame Over\n");
		break;
	}
	else {
		printf("Choose Lohan or Kepiting to be feed\n");
		printf("If you want to see their status, choose Status\n");
		scanf("%s",choose);		
		if(strcmp(choose,"Lohan")==0) {
			printf("\nYour Lohan's previous status: %d\n",lohan);			
			lohan = lohan + 10;
			printf("After feed, Lohan's status: %d\n",lohan);
		}
		else if (strcmp(choose,"Kepiting")==0) {
			printf("\nYour Kepiting's previous status: %d\n",kepiting);
			kepiting = kepiting + 10;
			printf("After feed, Kepiting's status: %d\n",kepiting);
		}
		else if (strcmp(choose,"Status")==0) {
			printf("\nLohan's Status: %d\n",lohan);
			printf("Kepiting's Status: %d\n",kepiting);
		}
	}
	}
}
