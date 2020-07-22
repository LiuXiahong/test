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
//P5714 【深基3.例7】肥胖问题
#include<bits/stdc++.h>
using namespace std;
double m,h,bmi;
int main()
{
	cin>>m>>h>>bmi;
	bmi=m/(h*h);
	if(bmi>=24)
	{
		cout<<bmi<<endl<<"Overweight";
	}
	if(bmi>=18.5&&bmi<24)
	{
		cout<<"Normal";
	}
	if(bmi<18.5)
	{
		cout<<"Underweight";
	}
	return 0;
}