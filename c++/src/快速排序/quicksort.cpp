#include<bits/stdc++.h>
using namespace std;
int a[1000],n;
void qsort(int l,int r)//key等于左边(l) 
{
	int key,t,i=l,j=r;
	if(l>r)
	{
		return;
	}
	key=a[l];
	while(i!=j)
	{
		while(a[j]>=key&&i<j)
			j--;
		while(a[i]<=key&&i<j)
			i++;
		if(i<j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
		}
	}
	a[l]=a[i];
	a[i]=key;
	qsort(l,i-1);
	qsort(i+1,r);
}

void qisort(int l,int r)//mid改进版 
{
	int key,t,i=l,j=r;
	key=a[(l+r)/2];
	while(i<=j)
	{
		while(a[j]>key)
			j--;
		while(a[i]<key)
			i++;
		if(i<=j)
		{
			t=a[i];
			a[i]=a[j];
			a[j]=t;
			i++;
			j--;
		}
	}
	if(l<j)
	    qisort(l,j);
	if(i<r)
	    qisort(i,r);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(0,n-1); 
	//qisort(0,n-1); 
	for(int i=0;i<n;i++)
	{
		printf("%d ",a[i]);
	}
}
