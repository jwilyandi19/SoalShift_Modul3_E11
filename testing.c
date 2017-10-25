#include<stdio.h>
int main(int n, char *x[])
{
int i;
printf("Command line arguments are:\n");
for(i=0;i<n;i++)
   printf("%s\n",x[i]);
return 0;
}
