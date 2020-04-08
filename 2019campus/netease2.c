#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/mman.h>

#define min(x,y) (x<y?x:y)

typedef struct Work
{
	unsigned char deadline;
	unsigned char cost;
}Work_t;

typedef struct WorkList
{
	unsigned char num;
	Work_t work[20];
}WorkList_t;


void swap(int *p1, int *p2)
{
	int t = *p1;
	*p1 = *p2;
	*p2 = t;	
}

unsigned int Work_permutation(int a[],int index,int size,WorkList_t *P_work)
{
	unsigned int i, j; 
	unsigned int date  = 0;
	unsigned int new_delay = 0;
	static unsigned int min_delay = 999;
	if(index == size)
	{	new_delay = 0;
		for(i = 0; i < size; i++)
			{					
				date += P_work->work[a[i]-1].cost;
				if(date > P_work->work[a[i]-1].deadline)
					new_delay += date - P_work->work[a[i]-1].deadline;
			}
		if(new_delay < min_delay)	
			min_delay = new_delay;

	}
	else
	{
		for(j = index; j < size; j++)
			{
				swap(&a[j],&a[index]);
				Work_permutation(a,index+1,size,P_work);
				swap(&a[j],&a[index]);
			}
	}
	return min_delay;
}

/*func:input the rect data*/
void Work_input(WorkList_t *P_work)
{
	unsigned int num;
	unsigned char i;
	float ratio1,ratio2;

	//printf("\r\n################input NUM###################\r\n");
	scanf("%d", &num);
	P_work->num = num;
	while(num<1||num>20)
		{
		printf("out of range,pls input a num in [1,20] input your num again\n\n");
		scanf("%d", &num);
		}

	for(i = 0; i < num; i++){
        scanf("%d", &P_work->work[i].deadline);
        scanf("%d", &P_work->work[i].cost);
    }
	//printf("finished your input\n");
}


/*func:output the rect date in new order*/
void Work_output(WorkList_t *P_work)
{
	unsigned char delay = 0;	
	unsigned char i = 0;
	unsigned char num = P_work->num;
	int a[num];
	for(i = 0; i < 	num; i++)
		a[i] = i+1;
	delay = Work_permutation(a,0,num,P_work);
	printf("%d\n",delay);
}

int main(void)
{
	WorkList_t Mywork = {0};
	Work_input(&Mywork);
	Work_output(&Mywork);
    return 0;
}





