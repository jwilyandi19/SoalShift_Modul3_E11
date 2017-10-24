#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/ipc.h>
#include<sys/shm.h>

int main () {
	key_t key = 1234;
	char list_gun[6][15];
	int *stock;
	strcpy(list_gun[0],"MP4A1");
	strcpy(list_gun[1],"PM2-V1");
	strcpy(list_gun[2],"SPR-3");
	strcpy(list_gun[3],"SS2-V5");
	strcpy(list_gun[4],"SPG1-V3");
	strcpy(list_gun[5],"MINE");
	int shmid = shmget(key,sizeof(int),IPC_CREAT | 0666);
	stock = shmat(shmid,NULL,0);
	char gun[15];
	int buy;
	printf("You are a buyer. You can see stock or buy gun\n");
	char choose[6];
	while(1) {
		printf("\nChoose List or Buy\n");
		scanf("%s",choose);
		if(strcmp(choose,"List")==0) {
			for(int i=0; i<6; i++) {
					printf("%s %d\n",list_gun[i],stock[i]);
				
			}
		}
		else if (strcmp(choose,"Buy")==0) {
			scanf("%s %d",gun,&buy);
			for(int i=0; i<6; i++) {
				if(strcmp(list_gun[i],gun)==0) {
					
					if(buy > stock[i]) printf("barang di stock tidak cukup\n");
					else stock[i] = stock[i] - buy;
				}
			}
		}
	}
	shmdt(stock);
	shmctl(shmid,IPC_RMID,NULL);
}
