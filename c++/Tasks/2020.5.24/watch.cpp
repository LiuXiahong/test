//[NOI Online #3 入门组]买表
//相关链接🔗 https://www.luogu.com.cn/problem/P6567
#include<bits/stdc++.h>
using namespace std;
bitset<500005> dp;
int n,m,a,k,l;
int main()
{
	scanf("%d%d",&n,&m);
	dp[0]=1;
	for(int i=0;i<n;i++)
	{
		scanf("%d%d",&k,&a);
		for(l=1;a>=l;l*=2)
		{
			dp|=dp<<l*k;
			a-=l;
		}
		if(a*k)
			dp|=dp<<a*k;	
	}
	while(m--)
	{
		scanf("%d",&k);
		puts(dp[k]?"Yes":"No");
	}
	return 0;
}