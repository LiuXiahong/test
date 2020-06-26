#include<stdio.h>
int main()
{
	int book[1001]= {0},a[1001]= {0},n,t;
	scanf("%d",&n);
	for(int i=0; i<n; i++)
	{
		scanf("%d",&t);
		a[t]=1;
		book[t]++;
	}
	for(int i=0; i<1001; i++)
	{
		if(a[i]==1)
		{
			printf("%d %d\n",i,book[i]);
		}
	}
}
