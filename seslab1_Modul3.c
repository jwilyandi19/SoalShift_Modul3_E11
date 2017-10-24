#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>

pthread_t tid[2];

void* copyandcopy (void *arg) {
	unsigned long i=0;
	pthread_t id = pthread_self();
	if(pthread_equal(id,tid[0])) {
	char ch;
	FILE *fp,*fp1;
	int pos;
	fp = fopen("/home/jwilyandi19/modul3/baca.txt","r");
	if(fp==NULL) printf("baca.txt not found\n");
	else {
	fp1 = fopen("/home/jwilyandi19/modul3/salin1.txt","w+");
	fseek(fp,0L,SEEK_END);
	pos = ftell(fp);
	fseek(fp,0L,SEEK_SET);
	while(pos--) {
		ch = fgetc(fp);
		fputc(ch,fp1);
	}
	fclose(fp);
	fclose(fp1); }
	}
	else if (pthread_equal(id,tid[1])) {
	char ch;
	FILE *fp,*fp1;
	int pos;
	fp = fopen("/home/jwilyandi19/modul3/salin1.txt","r");
	if(fp==NULL) printf("salin1.txt not found\n");
	else {
	fp1 = fopen("/home/jwilyandi19/modul3/salin2.txt","w+");
	fseek(fp,0L,SEEK_END);
	pos = ftell(fp);
	fseek(fp,0L,SEEK_SET);
	while(pos--) {
		ch = fgetc(fp);
		fputc(ch,fp1);
	}
	fclose(fp);
	fclose(fp1); }
	}
	return NULL;
}
	

int main () {
	int i = 0;
	int err;
	while(i<2) {
	err = pthread_create(&(tid[i]),NULL,&copyandcopy,NULL);
	if(err!=0) printf("\ncan't create thread: [%s]",strerror(err));
	else printf("\nthread made");
	sleep(1);
	i++; }
	pthread_join(tid[0],NULL);
	pthread_join(tid[1],NULL);
}
	
	
