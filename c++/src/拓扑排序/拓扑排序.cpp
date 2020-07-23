#include<bits/stdc++.h>
using namespace std;
vector<int> v[5001];//存储有向无环图
queue<int> q;//bfs队列
int in[50001];//存储每一个节点的入度
int a,b,n,m;
int main()
{
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        cin>>a>>b;
        v[a].push_back(b);
        in[b]++;//b节点的入度+1
    }
    for(int i=1;i<=n;i++)
    {
        if(in[i]==0)//如果有一个节点的入度为0(起点)
        {
            q.push(i);//将此节点压入队列作为起点
        }
    }
    //bfs
    while(q.size())
    {
        int t=q.front();//取出头部节点
        q.pop();//弹出头部节点
        for(int i=0;i<v[t].size();i++)//遍历
        {
            int node_t=v[t][i];
            in[node_t]--;//将此节点的入度-1,因为已经遍历
            if(in[node_t]==0)//如果此节点入度为0
            {
                q.push(node_t);//压入队列,作为下一次起点
            }
        }
    }
}