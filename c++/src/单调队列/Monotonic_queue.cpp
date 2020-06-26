#include<stdio.h>
/*
    6 2
    8 1 3 6 4 7
    输出
    8 8 8 6 6 7
*/ 
//这里维护了一个从小到大的单调队列。队首最小，队尾最大 
int que[100];
int idxNum[100];
int cnt=0,head=0,tail=0;
int width=3;//区间宽度 
int push(int value,int idx)
{
	//维护队列单调性，从尾部插入数，如果数比前面还大，则弹出前面的数， 
	while(tail>head&&que[tail-1]<value) tail--;
	//插入尾数 
	que[tail]=value;
	idxNum[tail]=idx;//插入索引，是为了跟踪区间长度是否超出 
	tail++;
	//检查头部是否需要弹出
	//单调队列插入的数的特点是，idx一定是从队首从小到大排列。 
	if(idx-idxNum[head]>width)
	{//弹出头部 
		head++;
	} 
	return que[head];
}

int main()
{
	int n;
	scanf("%d%d",&n,&width);
	int a;
	int b[100];
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a);
		b[i]=push(a,i);
		printf("%d ",b[i]);
	}
	return 0;
}
