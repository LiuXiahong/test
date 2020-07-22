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
//P5716 【深基3.例9】月份天数
#include<bits/stdc++.h>  //文件头
using namespace std;

int year,month;   //定义年和月
int a[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};  //定义月份对应天数数组
int main()
{
    cin>>year>>month;
    if((year%4==0&&year%100!=0)||year%400==0)a[2]=29;   //判断闰年
    cout<<a[month];
    return 0;
}
