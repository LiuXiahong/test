#include<stdio.h>
int main()
{
	int a[5],i,max=0;
	for(i=0;i<=4;i++)
		scanf("%d",&a[i]);
	a[0]=max;
	for(i=0;i<=4;i++)
	{
		if(a[i]>max)
		{
			max=a[i];
		}
	}
	printf("%d",max);
}
