#include<stdio.h>
int main()
{
	int a[100]={0},b[100]={0},n,t;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
	}
	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			if(b[j]>b[i])
			{
				t=b[j];
				b[j]=b[i];
				b[i]=t;
				t=a[j];
				a[j]=a[i];
				a[i]=t;
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}

