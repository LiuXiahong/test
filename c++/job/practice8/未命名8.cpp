#include<stdio.h>
int main()
{
	int a[5]={5,4,1,2,3},t;
	for(int i=0;i<=4;i++)
	{
		for(int j=0;j<4-i;j++)
		{
			if(a[j]>a[j+1])
			{
				t=a[j];
				a[j]=a[j+1];
				a[j+1]=t;
			}
		}
	}
	for(int i=0;i<=4;i++)
		printf("%d ",a[i]);
}
