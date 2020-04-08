#include<stdio.h>

typedef struct MultObj
{
	int value;
	int singleV;
	int singlenum;

}MultObj;

int max(int a,int b)
{
return a>b?a:b;
}
	

int main()
{
	int total_num,totalV;
	
	int i,v,k,m;
	scanf("%d %d",&total_num,&totalV);
	int Plan[totalV+1];
	for(i=0;i<totalV+1;i++)
		Plan[i]=0;
	MultObj Obj[totalV+1];
	memset(Obj,0,sizeof(Obj));
	for(i=1;i<total_num+1;i++)
		{
			scanf("%d %d %d",&Obj[i].value,&Obj[i].singleV,&Obj[i].singlenum);
		}

	for(i=1;i<total_num+1;i++)
		{
			if(Obj[i].singlenum*Obj[i].singleV > totalV)
				{
					for(v = Obj[i].singleV;v<totalV+1;v++)
						Plan[v] = max(Plan[v],Plan[v-Obj[i].singleV]+Obj[i].value);
				}
			else
				{
					k=1;
					m = Obj[i].singlenum ;
					while(k<m )
						{
							for(v = totalV;v>=k*Obj[i].singleV;v--)
								Plan[v] = max(Plan[v],Plan[v-Obj[i].singleV*k]+Obj[i].value*k);
							m=m-k;
							k=2*k;
						}
					for(v = totalV;v>=m*Obj[i].singleV;v--)
						Plan[v] = max(Plan[v],Plan[v-Obj[i].singleV*m]+Obj[i].value*m);	
				}
		}
	printf("%d\n",Plan[totalV]);
	return 0;
}
