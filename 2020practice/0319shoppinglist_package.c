#include<stdio.h>

typedef struct MultObj
{
	int value;
	int singleV;
	int index;
	int group;
	int target;
	int flag;
}MultObj;

int max(int a,int b)
{
return a>b?a:b;
}
	

int main()
{
	int total_num,totalV;
	
	int i,v,k,m,j;
	scanf("%d %d",&totalV,&total_num);
	int Plan[3200] = {0};
	
	int Plan_temp[3200] = {0};
	int F[60][3200] = {0};

	MultObj Obj[60];
	memset(Obj,0,sizeof(Obj));
	for(i=1;i<total_num+1;i++)
		{
				scanf("%d %d %d",&Obj[i].singleV,&Obj[i].value,&Obj[i].index);
				Obj[i].target = Obj[i].value*Obj[i].singleV/10;
				Obj[i].flag = 0; 
				if(Obj[i].index == 0)
					Obj[i].group = i;
				else
					{
					Obj[i].group = Obj[i].index;
					
					Obj[Obj[i].index].flag = 1;
					}

		}

	for(i=1;i<total_num+1;i++)
		{
		if(Obj[i].index!=0)
			continue;
		if(Obj[i].flag == 1)
			{
			for(k=1;k<totalV/10+1;k++)	
			 Plan_temp[k] = 0;
			for(j=1;j<total_num+1;j++)
				{
		
					 if((Obj[j].group == i)&&(Obj[j].index!=0))
						for(v=totalV/10-Obj[i].singleV/10;v>=Obj[j].singleV/10;v--)
							{
							Plan_temp[v] = max(Plan_temp[v],Plan_temp[v-Obj[j].singleV/10]+Obj[j].target);
							}
				}
			for(v=0;v<=totalV/10-Obj[i].singleV/10;v++)
				{
				F[i][v+Obj[i].singleV/10] =Plan_temp[v]+Obj[i].target;
				printf("F[%d][%d] = %d\n",i,v+Obj[i].singleV/10,F[i][v+Obj[i].singleV/10]);
				}
			}
		else
			{
					for(v=totalV/10.;v>=Obj[i].singleV/10;v--)
						{
						F[i][v] = F[i][v-Obj[i].singleV/10]+Obj[i].target;
						}				
			}
		}
	for(i=1;i<total_num+1;i++)			
		for(v=totalV/10;v>=0;v--)
			for(k=0;k<=v;k++)
				Plan[v]=max(Plan[v],Plan[v-k]+F[i][k]);

	printf("%d\n",Plan[totalV/10]*10);
	return 0;
}

