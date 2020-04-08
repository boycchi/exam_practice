#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/mman.h>

typedef struct fruitJob
{
	char fruitName[8];
	int  workerNum;
	int  workerWeight;
}job;

int main(void)
{
	char *p;	
	char str[10];
	job Wjob[100];
	job Tjob;
	char Fruitsort[100][15];
	int N;
	int i=0;
	int j=0;
	int M=0;
	int k=0;
	int sum = 0;
	scanf("%d",&N);
	for(i=0;i<N;i++)
		{
		scanf("%s %d %d",Wjob[i].fruitName,&Wjob[i].workerNum,&Wjob[i].workerWeight);
		}
	for(i=0;i<N;i++)
	{
		if(strcmp(Fruitsort[M],Wjob[i].fruitName)!=0)
		{
			strcpy(Fruitsort[M],Wjob[i].fruitName);
			M++;
		}
	}
	for(j=0;j<M;j++)
		for(i=0;i<N;i++)
			for(k=0;k<N-i;k++)
			if((strcmp(Fruitsort[j],Wjob[i].fruitName)==0)&&(strcmp(Fruitsort[j],Wjob[k].fruitName)==0))
				{
					if(Wjob[i].workerWeight<Wjob[k].workerWeight)
						{
							Tjob=Wjob[i];
							Wjob[i]=Wjob[k];
							Wjob[k]=Tjob;	
						}
				}
	for(j=0;j<M;j++)
		for(i=0;i<N;i++)
			if(strcmp(Fruitsort[j],Wjob[i].fruitName)==0)
				printf("%s %d %d\n",Wjob[i].fruitName,Wjob[i].workerNum,Wjob[i].workerWeight);
	return 0;
}
