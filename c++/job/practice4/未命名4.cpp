#include<stdio.h>
int main()
{
	int a,b,i=2;
	scanf("%d",&a);
	while(1)
	{	
		if(a%i==0)
		{
			b=1;
			break;
		}
		i++;
	}
	if(b==1)
		printf("NO");
	else
		printf("YES");
} 

