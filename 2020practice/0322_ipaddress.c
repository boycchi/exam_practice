#include<stdio.h>
#include<string.h>

typedef struct IpAddress
{
	unsigned char ip[4];
	unsigned char mask[4];
}IpAddress;

int main()
{
	IpAddress Input_Inst = {0};
	char input[50];
	char *p;
	while(scanf("%s",input)!=EOF);
		{
//			sscanf(input,"%3s~%3s",Input_Inst.ip,Input_Inst.mask);
			p = strtok(input,"~");
			strcpy(Input_Inst.ip,p);
			
			p = strtok(NULL,"~");
			
			strcpy(Input_Inst.mask,p);
			printf("%s %s\n",Input_Inst.ip,Input_Inst.mask);
		}
	return 0;
}

