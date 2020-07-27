#include<bits/stdc++.h>
using namespace std;
struct node
{
	int to,v;
	int pre;
};
node E[500001];
int total=1;

queue<int> q;

int s;
int dis[500001],flag[500001],V[500001];
int a,b,c;
int main()
{
	int n,m;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);
		E[total].to=b;
		E[total].v=c;
		E[total].pre=V[a];
		V[a]=total;
		total++;
	}
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	q.push(s);
	while(q.size())
	{
		int t=q.front();
		q.pop();
		for(int j=V[t];j!=0;j=E[j].pre)
		{
			int tt=E[j].to;
			int v=E[j].v;
			if(dis[tt]>dis[t]+v)
			{
				dis[tt]=dis[t]+v;
				if(flag[tt]==0)
				{
					flag[tt]=1;
					q.push(tt);
				}
				
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==0x3f)
		{
			printf("%d ",((unsigned int)1<<31)-1);
		}
		else
		{
			printf("%d ",dis[i]);
		}
		
	}
	return 0;
}
//SPFA--他死了 