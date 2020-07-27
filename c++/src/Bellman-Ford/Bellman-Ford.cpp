#include<bits/stdc++.h>
using namespace std;

int dis[500001],flag[500001],V[500001];
int u[10],w[10],v[10];
int a,b,c;
int main()
{
	int n,m,s;
	scanf("%d%d%d",&n,&m,&s);
	for(int i=0;i<m;i++)
	{
		scanf("%d%d%d",&u[i],&w[i],&v[i]);
        /*
		scanf("%d%d%d",&a,&b,&c);
		E[total].to=b;
		E[total].v=c;
		E[total].pre=V[a];
		V[a]=total;
		total++;
        */
	}
	memset(dis,0x3f,sizeof(dis));
	dis[s]=0;
	int f;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(dis[w[j]]>dis[u[j]]+v[j])
			{
				f=1;
				dis[w[j]]=dis[u[j]]+v[j];
			}
		}
		if(f==0)
		{
			break;
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