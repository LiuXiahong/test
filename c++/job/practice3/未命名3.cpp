#include<stdio.h>
int main()
{
	int i=1,a,b=0,c=0;
	while(i<=5)
	{
		scanf("%d",&a);
		if(!(a%2==0))
		{
			b++;
		}
		else
		{
			c++;	
		}
		i++;
	}
	printf("%d:%d",b,c);
	//printf("\nProcess exited after 13.68 seconds with return value 0");
}
