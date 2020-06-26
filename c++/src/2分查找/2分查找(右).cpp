#include<bits/stdc++.h>
int main()
{
	int a[10]= {1,1,2,3,3,3,6,7,8,9};
	int n,r=10,l=0,mid;
	scanf("%d",&n);
	while(l<r)
	{
		mid=(l+r)/2;
		if(a[mid]==n)
		{
			l=mid+1;
		}
		else if(a[mid]>n)
		{
			r=mid;
		}
		else
		{
			l=mid+1;
		}
	}
	if(l-1<0||a[l-1]!=n)
	{
		printf("-1");
	}
	else
	{
		printf("%d",l-1);
	}
}
