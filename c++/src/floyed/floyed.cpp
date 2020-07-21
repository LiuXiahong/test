#include<bits/stdc++.h>
using namespace std;
const int INF=99999;
int dmap[7][7]={{0},
				{0,1  ,INF,INF,INF,1  ,INF},
				{0,INF,0  ,INF,INF,INF,INF},
				{0,INF,INF,0  ,1  ,INF,INF},
				{0,INF,INF,INF,0  ,INF,INF},
				{0,INF,INF,1  ,INF,0  ,INF},
				{0,INF,1  ,INF,1  ,1  ,0  }};
int n;
int main()
{
	
	for(int k=1;k<7;k++)
	{
		for(int i=1;i<7;i++)
		{
			for(int j=1;j<7;j++)
			{
				dmap[i][j]=min(dmap[i][j],dmap[i][k]+dmap[k][j]);//引入第三点使两点的距离缩短
			}
		}
	}
	if(dmap[1][6]==1)
	{
		printf("YES");
	}
	else
	{
		printf("NO");
	}
	return 0;
}