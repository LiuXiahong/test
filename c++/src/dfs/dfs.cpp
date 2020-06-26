#include<bits/stdc++.h>
using namespace std;
char dmap[100][100]={
                    "*************", 
                    "* #         *",
                    "*   ### ### *",
                    "*###  #    #*",
                    "* #  ###  # *",
                    "*           *",
                    "*# #########*",
                    "*  #     # E*",
                    "*   # ###  #*",
                    "* #         *",
                    "*************" 
                    };
int book[50][50];
int dx[4]={0,1,0,-1},dy[4]={1,0,-1,0};
int n,m,ans=99999;
void dfs(int x,int y,int step)//递归函数
{
    if(dmap[x][y]=='E')//如果终点到了...
    {
        if(step<ans)
        {
            ans=step;//保存当前的值(万一这次是最短呢(￣y▽,￣)╭ )
        }
        return;//返回
    }
    for(int i=0;i<4;i++)
    {
        int tx=x+dx[i];
        int ty=y+dy[i];
        if(tx<0||tx>=10||ty<0||ty>=13||dmap[tx][ty]=='#'||dmap[tx][ty]=='*')//如果有墙或者到"边境之地"(有点不对劲呢)
        {
            continue;//尝试另一个方向
        }
        if(book[tx][ty]==0)//如果没有走过
        {
            book[tx][ty]=1;//标记此点
            dfs(tx,ty,step+1);
            book[tx][ty]=0;
        }
    }
    return;
}
int main()
{
    book[1][1]=1;//标记起点
    dfs(1,1,0);//开始遍历
    cout<<ans;//输出答案
    return 0;
}