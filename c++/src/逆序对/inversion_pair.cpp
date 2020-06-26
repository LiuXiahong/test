#include<stdio.h>
#include<memory.h>
int a[10]={8,3,7,2,5,4,6,1,10,9};
int c[10];
int d=0;
void mergeSort(int l,int r)
{
	if(l>=r) return ;
	int m=(l+r)/2;
	mergeSort(l,m);
	mergeSort(m+1,r);
	int t1=l,t2=m+1,t=0;
	while(t1<=m&&t2<=r)
	{
		if(a[t1]<=a[t2])
		{
			c[t]=a[t1];
			t++;
			t1++;
		}
		else
		{
			d+=(m-t1)+1;
			c[t++]=a[t2++];
		}
	}
	while(t1<=m)
	{
		c[t++]=a[t1++];
	}
	while(t2<=r)
	{
		c[t++]=a[t2++];
	}
	memcpy(a+l,c,t*sizeof(int));
}
int main()
{
	mergeSort(0,9);
	printf("%d",d);
}