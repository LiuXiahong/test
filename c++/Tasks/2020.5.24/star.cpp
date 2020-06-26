#include<bits/stdc++.h>
using namespace std;
int n,m,t,sum,ans,wt,maxn;
char mapn[100][100];
int book[100][100],dix[1000];
int tx,ty;
int dx[8]={0,1,0,-1,1,-1,1,-1},dy[8]={1,0,-1,0,1,-1,-1,1};
/*
5 7
*......
..**..*
.*...*.
...*...
....*..
*/
void dfs(int x,int y)
{
    mapn[x][y]='.';
    for(int i=0;i<8;i++)
    {
        tx=x+dx[i];
        ty=y+dy[i];
        if(tx<0||tx>=n||ty<0||ty>=m)
        {
            continue;
        }
        if(mapn[tx][ty]=='*'&&book[tx][ty]==0)
        {
            ans++;
            book[tx][ty]=1;
            dfs(tx,ty);
            book[tx][ty]=0;
        }
    }
    return;
}
int main()
{
    cin>>n>>m;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cin>>mapn[i][j];
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(mapn[i][j]=='*')
            {
                ans=0;
                sum++;
                book[i][j]=1;
                dfs(i,j);
                dix[t++]=ans;
                maxn=max(maxn,ans);
            }
        }
    }
    for(int i=0;i<t;i++)
    {
        if(dix[i]==maxn)
        {
            wt+=dix[i];
        }
    }
    cout<<sum<<' '<<wt;
    return 0;
}