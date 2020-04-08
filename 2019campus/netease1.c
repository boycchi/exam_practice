#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <ctype.h>
#include <sys/mman.h>

#define min(x,y) (x<y?x:y)

typedef struct Strectangle
{
	unsigned char width;
	unsigned char height;
	unsigned int  area;
	float aspect_ratio;	
}Strectangle_t;


typedef struct StrecList
{
	unsigned char rec_num;
	Strectangle_t strectangle[100];	
}StrecList_t;

/*func:input the rect data*/
void rectangle_input(StrecList_t *Pst_StrecList)
{
	unsigned char num;
	unsigned char i;
	float ratio1,ratio2;

	//printf("\r\n################input NUM###################\r\n");
	//printf("STEP1:pls input the rec_num N = ?\n");
	scanf("%d", &num);
	while(num<=0||num>100)
		{
		printf("out of range,pls input a num in (0,100] input your num again\n\n");
		scanf("%d", &num);
		}
	Pst_StrecList->rec_num = num;
	//printf("\r\n################input w&h###################\r\n");
	//printf("STEP2:pls input the w&h of your rect = ?\n");
	for(i = 0; i < num; i++){
	 	//printf("It's No.%d rect now\n",i+1);
		//printf("input your w\n");
        scanf("%d", &Pst_StrecList->strectangle[i].width);
		while(Pst_StrecList->strectangle[i].width<=0||Pst_StrecList->strectangle[i].width>100)
		{
			printf("out of range,pls input a num in (0,100] input your w again\n");
			scanf("%d", &Pst_StrecList->strectangle[i].width);
		}
		//printf("input your h\n");
        scanf("%d", &Pst_StrecList->strectangle[i].height);
		while(Pst_StrecList->strectangle[i].height<=0||Pst_StrecList->strectangle[i].height>100)
		{
			printf("out of range,pls input a num in (0,100] input your h again\n");
			scanf("%d", &Pst_StrecList->strectangle[i].height);
		} 

		ratio1 = (float)Pst_StrecList->strectangle[i].height / Pst_StrecList->strectangle[i].width;
		ratio2 = (float)Pst_StrecList->strectangle[i].width  / Pst_StrecList->strectangle[i].height;
		Pst_StrecList->strectangle[i].aspect_ratio = min(ratio1,ratio2);
		Pst_StrecList->strectangle[i].area = Pst_StrecList->strectangle[i].height * Pst_StrecList->strectangle[i].width;
		//printf("radio = %f\n",Pst_StrecList->strectangle[i].aspect_ratio );
    }
	//printf("finished your input\n");
}

/*func:sort the rect struct according to specfic rules*/
void rectangle_sort(StrecList_t *Pst_StrecList)
{
	unsigned char i;
	unsigned char j;
	Strectangle_t strectangle_temp;
	unsigned char num = Pst_StrecList->rec_num;
	for(i = 0; i < num-1 ;i++)
	{
		for(j = 0; j < num-1-i ;j++)
		{
			if((Pst_StrecList->strectangle[j].area)>(Pst_StrecList->strectangle[j+1].area))
				{
					strectangle_temp = Pst_StrecList->strectangle[j];
					Pst_StrecList->strectangle[j] = Pst_StrecList->strectangle[j+1];
					Pst_StrecList->strectangle[j+1] = strectangle_temp;
				}
			else if((Pst_StrecList->strectangle[j].area)==(Pst_StrecList->strectangle[j+1].area))
				{
					if((Pst_StrecList->strectangle[j].aspect_ratio)<(Pst_StrecList->strectangle[j+1].aspect_ratio))
					{
						strectangle_temp = Pst_StrecList->strectangle[j];
						Pst_StrecList->strectangle[j] = Pst_StrecList->strectangle[j+1];
						Pst_StrecList->strectangle[j+1] = strectangle_temp;
					}
					else if((Pst_StrecList->strectangle[j].aspect_ratio)==(Pst_StrecList->strectangle[j+1].aspect_ratio))
						{
							if((Pst_StrecList->strectangle[j].width)>(Pst_StrecList->strectangle[j+1].width))
							{
								strectangle_temp = Pst_StrecList->strectangle[j];
								Pst_StrecList->strectangle[j] = Pst_StrecList->strectangle[j+1];
								Pst_StrecList->strectangle[j+1] = strectangle_temp;
							}
						}
				}
		}
	}
}

/*func:output the rect date in new order*/
void rectangle_output(StrecList_t *Pst_StrecList)
{
	unsigned char num = Pst_StrecList->rec_num;	
	unsigned char i;
	//printf("\r\n################output###################\r\n");
	for(i = 0; i < num ;i++)
	{
		//printf("No%d:width:%d height:%d\n",i+1,Pst_StrecList->strectangle[i].width,Pst_StrecList->strectangle[i].height);
		printf("%d %d ",Pst_StrecList->strectangle[i].width,Pst_StrecList->strectangle[i].height);
	}
}

int main(void)
{
	StrecList_t MyStrecList = {0};
	rectangle_input(&MyStrecList);
	rectangle_sort(&MyStrecList);
	rectangle_output(&MyStrecList);
    return 0;
}





