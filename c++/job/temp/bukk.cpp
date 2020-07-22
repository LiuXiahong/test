/*
#include<bits/stdc++.h>
using namespace std;
struct p
{
	int v,pt;
	bool operator<(const p &b) const
	{
		return v<b.v;
	}
};
struct edge
{	
	int v,to;
};
int dis[10],flag[10];//标记数组
vector<edge> V[10];
priority_queue<p> q;
int a,b,c;
int idx;
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);//读入边
		edge t={c,b};
		V[a].push_back(t);//设定边
	}
	memset(dis,0x3f,sizeof(dis));//初始化dis数组
	dis[1]=0;
	p t={0,1};
	q.push(t);
	//找白点;从所有黑点中找最小值
	for(int i=1;i<=n;i++)
	{
		t=q.top();
		q.pop();
		printf("%d ",t.pt);
		for(int j=0;j<V[t.pt].size();j++)
		{
			int tt=V[t.pt][j].to;
			int v=V[t.pt][j].v;
			if(dis[tt]>dis[t.pt]+v)
			{
				dis[tt]=dis[t.pt]+v;
				int tp=dis[tt];
				p ttt={dis[tt],tt};
				q.push(ttt);
			}
		}
		
	}
	for(int i=1;i<=n;i++)//输出
	{
		printf("%d ",dis[i]);
	}
	return 0;
}
*/
//P5715	【深基3.例8】三位数排序
#include<bits/stdc++.h>
using namespace std;
int a[3];
int main()
{
	cin>>a[0]>>a[1]>>a[2];
	sort(a,a+3);
	cout<<a[0]<<' '<<a[1]<<' '<<a[2];
	return 0;
}