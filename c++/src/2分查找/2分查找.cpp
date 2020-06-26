#include<bits/stdc++.h>
int main()
{
	int a[10]={0,1,2,3,4,5,6,7,8,9};
	int n,r,l,mid;
	scanf("%d",&n);
	while(l<=r)
	{
		mid=(l+r)/2;
		if(a[mid]==n)
		{
			printf("%d",mid);
			return 0;
		}
		else if(a[mid]>n)
		{
			r=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	printf("No");
}
