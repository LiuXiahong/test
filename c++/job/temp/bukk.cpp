/*
#include<bits/stdc++.h>
using namespace std;
int sum=1,t;
long long x,k;
long long p[10000],v[10000],people[10000],ans[10000];//p为记录质数,v为标记质数
/*
int f(int n)
{
    for(int i=2;i<sqrt(n);i++)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}
/
int main()
{
    cin>>x>>k;
    v[0]=v[1]=1;
    int cnt=0;
    for (int i = 2; i <= x; i++)
    {
        if (!v[i]) //如果i为质数
        {
            p[++cnt] = i; //记录质数
        }
        for (int j = 1; j <= cnt && i *p[j]<=x; j++)
        {
            v[i * p[j]] = 1; //标记已找到的质数
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
    t=p[1];
    while(1)
    {
        if(x==1)
        {
            break;
        }
        if(x%t==0)
        {
            x/=t;
            people[t]++;
        }
        else
        {
            sum++;
            t=p[sum];
        }
    }
    for(int i=0;i<k;i++)
    {
        ans[i]=pow(p[sum],people[p[sum]]);
        sum--;
    }
    sort(ans,ans+k);
    for(int i=k-1;i>=0;i--)
    {
        cout<<ans[i]<<' ';
    }
    return 0;
}
*/
#include<bits/stdc++.h>
using namespace std;
struct node
{
    int time,money;
}dix[100000];
int n,m;
int use[100000];
bool cmp(node a,node b)
{
    return a.money>b.money;
}
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>dix[i].time;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>dix[i].money;
    }
    sort(dix+1,dix+m+1,cmp);
    for(int i=1;i<=m;i++)
    {
        for(int j=dix[i].time;j>=1;j--)
        {
            if(use[j]==0)
            {
                use[j]=1;
                dix[i].money=0;
                break;
            }
        }
    }
    for(int i=1;i<=m;i++)
    {
        n-=dix[i].money;
    }
    cout<<n;
    return 0;
}