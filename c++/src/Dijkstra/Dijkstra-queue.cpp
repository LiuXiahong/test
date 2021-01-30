#include<bits/stdc++.h>
using namespace std;
struct p
{
	int v;
	int pt;
	bool operator<(const p &b) const
	{
		return v>b.v;
	}
};
struct edge
{
	int v;
	int to;
};
priority_queue<p> qq;
vector<edge> V[10001];
int dis[10001],flag[10001];/*标记数组*/
int n,m,k;
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=m;i++)
	{
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);//读入边
		edge t={c,b};
		V[a].push_back(t);//设定边
	}
	memset(dis,0x3f,sizeof(dis));//初始化dis数组
	dis[k]=0;
	p t={0,k};
	qq.push(t);
	for(int i=1;i<=n&&qq.size();)
	{
		t=qq.top();
		qq.pop();
		if(flag[t.pt]==1)
			continue;
		flag[t.pt] =1;
		i++;
		for(int j=0;j<V[t.pt].size();j++)
		{
			int tt=V[t.pt][j].to;
			int v=V[t.pt][j].v;
			if(dis[tt]>dis[t.pt]+v)
			{
				dis[tt]=dis[t.pt]+v;
				p ttt={dis[tt],tt};
				qq.push(ttt);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(dis[i]==0x3f3f3f3f)
		{
			printf("%d ",((unsigned int)1<<31)-1);
		}
		else
		{
			printf("%d ",dis[i]);
		}
		
	}
}
