#include<bits/stdc++.h>
using namespace std;
int n,m,t,dir[100001],minn=100000;
int main()
{
    cin>>n>>m;
    for (int i=1;i<=n;i++)
    {
        cin>>dir[i];
    }
    for (int i=1;i<=n-m+1;i++)
    {
        for (int j=1;j<=m;j++)
        {
            t+=dir[i+j-1];
        }
        if (t<minn)
        {
            minn=t;
        }
        t=0;
    }
    cout<<minn;
    return 0;
}