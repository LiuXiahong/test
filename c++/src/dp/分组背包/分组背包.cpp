#include<bits/stdc++.h>
using namespace std;
const int size=10000,zu=100;
struct node
{
	int a,b;
}num[zu][size];
int idx[zu],dp[size];
int n,m,x;
int ai,bi,ci;
int main()
{
	scanf("%d%d",&m,&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d%d",&ai,&bi,&ci);
		x=max(x,ci);
		num[ci][idx[ci]].a=ai;
		num[ci][idx[ci]].b=bi;
		idx[ci]++;
	}
/*
for 所有的组k
    for v=V..0
        for 所有的i属于组k
　　　　　　f[v]=max{f[v],f[v-w[i]]+c[i]}
*/
	for(int i=1;i<=x;i++)
	{
		for(int j=m;j>=1;j--)
		{
			for(int k=0;k<idx[i];k++)
			{
				if(j>=num[i][k].a)
				{
					dp[j]=max(dp[j],dp[j-num[i][k].a]+num[i][k].b);
				}
			}
		}
	}
	printf("%d",dp[m]);
	return 0;
}