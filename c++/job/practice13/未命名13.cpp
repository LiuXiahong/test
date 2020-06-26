#include<stdio.h>
int book[1000000]={0},n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&book[i]);
	}
	int h=0,ans=0,t;
	for(int i=0;i<n;i++)
	{
		if(h<book[i])
			h=book[i];
	}
	while(1)
	{
		for(int i=0;i<n;i++)
		{
			if(book[i]-h>=0)
			{
				t=book[i]-h;
				ans+=t;
			}
			else
				ans+=0;
		}
		if(ans>=m)
		{
			printf("%d",h);
			break;
		}
		ans=0;
		h--;
	}
}
