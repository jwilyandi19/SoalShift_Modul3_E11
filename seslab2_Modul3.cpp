#include<stdio.h>
#include<string.h>
#include<pthread.h>
#include<stdlib.h>
#include<unistd.h>
#include<math.h>
#include<vector>
using namespace std;
int status;
//int awal;
//int akhir;

vector<int> primes;


struct variabel {
	int awal;
	int akhir;
};

bool is_prime(int i)
{
	int u=(int)sqrt(i);
	for (int j=0; primes[j]<=u&&j<primes.size();++j) {
		if (i%primes[j]==0)
		return false;
	}
	return true;
}



void* searchprime(void *){
    while(status != 1)
    status=1;
    for(int i=awal; i<=akhir; i++)
    {
	//printf("COK %d\n",i);
       	if (is_prime(i))
	{
	    primes.push_back(i);
	    printf("%d\n",i);
	}
    }
    status=0;
    return NULL;
}

int main()
{
    primes.push_back(2);
    int err;
    int n, t;
    scanf("%d%d",&n,&t);
    pthread_t tid[t];
    awal=2;
    akhir=n/t;
	status=0;
    for(int i=0; i<t; i++)
    {
        err = pthread_create(&(tid[i]),NULL,&searchprime,NULL);
        if(err!=0) printf("\ncan't create thread: [%s]",strerror(err));
    	else printf("\nthread made %d\n",i);
	sleep(1);
        awal=akhir+1;
        akhir+=akhir;
        if(awal+akhir-1>n)akhir=n;
    }
    for(int j=0; j<t; j++)
    {
        pthread_join(tid[j],NULL);
    }
}



