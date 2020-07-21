//P2419 [USACO08JAN]Cow Contest S
#include<bits/stdc++.h>
using namespace std;
int a,b,n,m,t,f[101][101];
int ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
	{
        cin>>a>>b;
        f[a][b]=1;
    }
    for(int k=1;k<=n;k++)
	{
        for(int i=1;i<=n;i++)
		{
            for(int j=1;j<=n;j++)
			{
              f[i][j]=f[i][j]|f[i][k]&f[k][j];
			}
		}
	}
    for(int i=1;i<=n;i++)
	{
        t=1;
        for(int j=1;j<=n;j++)
        if(i==j)
			continue;
		else
		{
			t=t&(f[i][j]|f[j][i]);
		} 
		ans+=t;
    }
    
}