#include<stdio.h>
int main()
{
	int a;
	scanf("%d",&a);
	while(1)
	{
		if(a!=1)	
		{
			if(a%2==0)
			{
				printf("%d/2=%d\n",a,a/2);
				a/=2;
			}
			else
			{
				printf("%d*3+1=%d\n",a,a*3+1);
				a=a*3+1;
			}
		}
		else
		{
			printf("End");
			break;
		}	
	}
} 
