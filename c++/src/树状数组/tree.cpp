#include<stdio.h>
int n;
int a[100];
int c[100];
int lowbit(int i)
{
	return i&(-i);
}
int sum(int m)
{
	int s=0;
	while(m>0)
	{
		s+=c[m];
		m-=lowbit(m);
	}
	return s;
}
void update(int i,int value)
{
	while(i<=n)
	{
		c[i]+=value;
		i+=lowbit(i); 
	}
}
int main()
{

	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		update(i,a[i]);
	}
	printf("%d",sum(3));
}