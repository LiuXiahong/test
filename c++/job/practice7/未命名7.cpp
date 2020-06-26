#include<stdio.h>
int main()
{
	int a[5]={5,6,8,3,2},b[5]={0};
	for(int i=0;i<=4;i++)
	{
		b[i]=a[4-i];
	}
	for(int j=0;j<=4;j++)
	{
		a[j]=b[j];
		printf("%d ",a[j]);
	}
} 
