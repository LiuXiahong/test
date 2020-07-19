//P4017
#include<bits/stdc++.h>
using namespace std;
const int MAX=80112002;
vector<int> v[5001];
queue<int> q;
int in[50001],out[50001],dis[5001];
int a,b,n,m;
long long ans;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        in[b]++;
        out[a]++;
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)
        {
            q.push(i);
            dis[i]=1;
        }
    }
    while(q.size())
    {
        int t=q.front();
        q.pop();
        for(int i=0;i<v[t].size();i++)
        {
            int node_t=v[t][i];
            in[node_t]--;
            dis[node_t]=(dis[node_t]+dis[t])%MAX;
            if(in[node_t]==0)
            {
                q.push(node_t);
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        if(out[i]==0)
        {
            ans=(ans+dis[i])%MAX;
        }
    }
    cout<<ans%MAX;
}