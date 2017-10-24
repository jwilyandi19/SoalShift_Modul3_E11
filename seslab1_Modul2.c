#include<stdlib.h>
#include<sys/types.h>
#include<unistd.h>
#include<stdio.h>
#include<sys/wait.h>

void run_a() {
	int i;
	for(int i=0; i<100; i++) {
		printf("%d\n",i);
	}
}

void run_b() {
	int i;
	for(int i=100; i<200; i++) {
		printf("%d\n",i);
	}
}

int main () {
	pid_t child_id;
	int stat;

	child_id = fork();
	//printf("Child ID: %d\n",(int)child_id);

	if(child_id<0) exit(EXIT_FAILURE);

	if(child_id==0) run_a();
	else {
	while((wait(&stat)) > 0 );

	run_b();

}
}
