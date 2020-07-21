#include<bits/stdc++.h>
using namespace std;
int dmap[6][6],dis[10],flag[10]/*标记数组*/;
int a,b,c;
int minn,idx;
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&a,&b,&c);//读入边
		dmap[a][b]=c;//设定边
	}
	memset(dis,0x3f,sizeof(dis));//初始化dis数组
	dis[1]=0;
	//找白点;从所有黑点中找最小值
	for(int j=1;j<=n;j++)
	{
		minn=99999;//设定最小值
		for(int i=1;i<=n;i++)
		{
			if(flag[i]==0&&dis[i]<minn)
			{
				minn=dis[i];//更新最小值
				idx=i;
			}
		}
		flag[idx]=1;//标记此点为白点
		for(int i=1;i<=n;i++)
		{
			if(dmap[idx][i]!=0)//如果两点之间可以到达
			{
				dis[i]=min(dis[i],dis[idx]+dmap[idx][i]);//引入第三点使两点之间的距离缩短
			}
		}
	}
	for(int i=1;i<=n;i++)//输出
	{
		printf("%d ",dis[i]);
	}
	return 0;
}
