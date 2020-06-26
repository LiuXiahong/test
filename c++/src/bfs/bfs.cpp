#include<bits/stdc++.h>
using namespace std;
struct node
{
	int x,y;//坐标
	int step;//步数
};
queue<node> q;//定义队列
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
int dx[4]={-1,1,0,0},dy[4]={0,0,-1,1};//定义方向数组
//int book[100][100];
/*
调试时的输出语句
void print()
{
	for(int i=1;i<=9;i++)
	{
		for(int j=1;j<=11;j++)
		{
			printf("%3d ",book[i][j]);
		}
		printf("\n");
	}
	printf("****************************************\n");
}
*/
int main() 
{
	node t={1,1,0};
	q.push(t);//压入起点
	dmap[1][1]='#';//记录
	//book[1][1]=0;
	while(q.size()/*防止崩溃*/)
	{
		t=q.front();//取出头部
		q.pop();//弹出头部
		if(dmap[t.x][t.y]=='E')//如果到达了终点
		{
			printf("%d",t.step);//输出
			break;//跳出循环
		}
		//book[t.x][t.y]=t.step;
		dmap[t.x][t.y]='#';//记录
		for(int i=0;i<4;i++)
		{
			int nx=t.x+dx[i];
			int ny=t.y+dy[i];
			if(dmap[nx][ny]!='*'&&dmap[nx][ny]!='#')//如果没有墙...
			{				
				node nt;
				nt.x=nx;
				nt.y=ny;
				nt.step=t.step+1;
				q.push(nt);//压入点
			}
		}
		//print();输出语句
	}
    return 0;
}
