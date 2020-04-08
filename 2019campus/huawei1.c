#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/mman.h>

typedef struct badEvent
{
	char eventName[8];
	int  eventNum;
}bEvent;

int main(void)
{
	char *p;	
	char str[10];
	bEvent warnEvent[100];
	bEvent realEvent[100];
	
	int i=0;
	int j=0;
	int k=0;
	int sum = 0;
	
	while(scanf("%s",str)!=EOF)
	{
		int duFlag = 0;
		p=strtok(str,",");
		strcpy(realEvent[i].eventName,str);
		p=strtok(NULL,",");
		if(*(p+1)=='\0')	
			realEvent[i].eventNum = (*p -'0');
		else if(*(p+2)=='\0')
			realEvent[i].eventNum = (*p -'0')*10 + (*(p+1) -'0');
		else
			realEvent[i].eventNum = 100;
		//printf("%s %d\n",realEvent[i].eventName,realEvent[i].eventNum);
		for(j=0;j<k;j++)
		{
			if(strcmp(warnEvent[j].eventName,realEvent[i].eventName) == 0)
				{
					warnEvent[j].eventNum += realEvent[i].eventNum;
					duFlag = 1;
					break;
				}
		}
		if(duFlag == 0)
		{
		    strcpy(warnEvent[k].eventName,realEvent[i].eventName);
			warnEvent[k].eventNum  = realEvent[i].eventNum;
			k++;
		}		
		i++;	
	}
		//printf("k=%d\n",k);
		for(j=0;j<k;j++)
		{
			if(warnEvent[j].eventNum>=10)
				sum++;
		}
			printf("%d\n",sum);
	return 0;
}
