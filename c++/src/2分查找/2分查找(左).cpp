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
			r=mid;
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
	if(l>9||a[l]!=n)
	{
		printf("-1");
	}
	else
	{
		printf("%d",l);
	}
}
