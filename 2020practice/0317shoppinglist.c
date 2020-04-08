#include<stdio.h>

typedef struct Objectattr{
    unsigned int v;
    unsigned char p;
    unsigned char q;
    unsigned int Target;
}Objectattr;
typedef struct Plan{
    unsigned int Target;
    unsigned int cost;
    unsigned char label[60];
}Plan;

int max(int a, int b){
    return a>b?a:b;
}

int main()
{
    int N,m;
    int i,j,k;
    scanf("%d %d",&N,&m);
    Objectattr obj[m];
    Plan plan[300] = {0};
    int count = 0;
    int temp_count = 0;
    int max_target = 0;
    for(i=0;i<m;i++)
    {
        scanf("%d %d %d",&obj[i].v,&obj[i].p,&obj[i].q);
        obj[i].Target = obj[i].v * obj[i].p;
        temp_count = count;
        if(obj[i].q == 0)
        {
            if(obj[i].v<=N)
            {
                k = 0;
                do
                {
                    if(plan[k].cost+obj[i].v<=N)
                    {
                        if(temp_count == 0)
                        {
                            plan[temp_count].Target = obj[i].Target;
                            max_target = max(max_target,plan[temp_count].Target);
                            plan[temp_count].label[i] = 1;
                            plan[temp_count++].cost = obj[i].v;   
                        }
                        else
                        {
                            plan[temp_count].Target = plan[k].Target+obj[i].Target;
                            max_target = max(max_target,plan[temp_count].Target);
                            plan[temp_count].label[i] = 1;
                            plan[temp_count++].cost = plan[k].cost+obj[i].v;
                            plan[temp_count].Target = obj[i].Target;
                            plan[temp_count].label[i] = 1;
                            max_target = max(max_target,plan[temp_count].Target);                            
                            plan[temp_count++].cost = obj[i].v;                            
                        }
                    }
                    else
                    {
                            plan[temp_count].Target = obj[i].Target;
                            max_target = max(max_target,plan[temp_count].Target);   
                            plan[temp_count].label[i] = 1;
                            plan[temp_count++].cost = obj[i].v;
                    }
                 k++;
                }while(k<count);
            }
        }   
        else
        {

            k = 0;
                do
                {
                    if(plan[k].label[obj[i].q-1] == 1)
                    {
                        if(plan[k].cost+obj[i].v<=N)
                        {

                            plan[temp_count].Target = plan[k].Target+obj[i].Target;
                            max_target = max(max_target,plan[temp_count].Target);
                            plan[temp_count].label[obj[i].q-1] = 1;
                            plan[temp_count++].cost = plan[k].cost+obj[i].v;
                        
                        }

                    }
                    k++;
                }while(k<count);

        }

        count = temp_count;
    }

printf("%d\n",max_target);            
    
    return 0;
        
}

