#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/mman.h>

#define min(x,y) (x<y?x:y)

int judge(int a,int b)
{
	int i = 0;
	if(b == 1) return 1;
	for (i = 2;i<b;i++)
	{
		if(b%i==0 && a%i==0) return 0;
	}
		return 1;
}
/*func:output the rect date in new order*/
float func(int n)
{
	int i,count = 0;
	float ratio;
	int num =n;
	for (i=1;i<=n;i++)
	{
		if(judge(i,n)==1) 
			{
				count++;
				//printf("11111\n");
			}
	}
	//printf("count = %d num =%d\n",count,num);
	ratio = (count/num);
return ratio;
}

int main(void)
{
	int num,i;
	float min=1,pc;
	scanf("%d", &num);
	for(i=1;i<=num;i++)
		{
			pc = func(i);
			if(pc < min)
			min = pc;
		}
	printf("%6f",min);
    return 0;
}





