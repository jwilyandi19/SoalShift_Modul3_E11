#include<stdio.h>
#include<unistd.h>
#include<string.h>

int main () {

	char list_gun[6][15];
	int stock[6];
	strcpy(list_gun[0],"MP4A1");
	strcpy(list_gun[1],"PM2-V1");
	strcpy(list_gun[2],"SPR-3");
	strcpy(list_gun[3],"SS2-V5");
	strcpy(list_gun[4],"SPG1-V3");
	strcpy(list_gun[5],"MINE");
	char gun[15];
	int adding;
	printf("You are a seller. You can see stock or add your stock\n");
	char choose[6];
	while(1) {
		printf("\nChoose List or Add\n");
		scanf("%s",choose);
		if(strcmp(choose,"List")==0) {
			for(int i=0; i<6; i++) {
				if(stock[i]>0)
					printf("%s %d\n",list_gun[i],stock[i]);
				
			}
		}
		else if (strcmp(choose,"Add")==0) {
			scanf("%s %d",gun,&adding);
			for(int i=0; i<6; i++) {
				if(strcmp(list_gun[i],gun)==0) {
					stock[i] = stock[i] + adding;
				}
			}
		}
	}
}
