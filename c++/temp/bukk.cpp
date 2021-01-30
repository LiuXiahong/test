// #include<bits/stdc++.h>
// #include<stdio.h>
// #include<windows.h>
// #include<conio.h>
// using namespace std;

// const int M=20,N=30;
// int elements[7][4]={
//     2,3,4,5,
//     1,3,5,7,
//     2,4,5,7,
//     3,5,4,6,
//     3,5,7,6,
//     2,4,6,7,
//     3,5,4,7
// };
// struct point
// {
//     int x,y;
// }cur[4],pre[10];
// long long LastTick;
// int fields[M][N];
// int color(int c)
// {
//     switch(c)
//     {
//     case 1: c=9;break;
//     case 2:
//     case 3: c=12;break;
//     case 4:
//     case 5: c=14;break;
//     case 6: c=10;break;
//     case 7: c=13;break;
//     default: c=7;break;
//     }
//     SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
//     return 0;
// }
// void add()
// {
//     int num=rand()%7;
    
//     for(int i=0;i<4;i++)
//     {
//         cur[i].x=elements[num][i]%2;
//         cur[i].y=elements[num][i]/2;
//     }
// }
// int check()
// {
//     for(int i=0;i<4;i++)
//     {
//         if(cur[i].x<0||cur[i].x>=M||cur[i].y>=N)
//         {
//             return 1;
//         }
//         if(fields[cur[i].x][cur[i].y])
//         {
//             return 1;
//         }
//     }
// }
// void hidden_cursor()//隐藏光标
// {
//   HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
//   CONSOLE_CURSOR_INFO cci;
//   GetConsoleCursorInfo(hOut,&cci);
//   cci.bVisible=0;//赋1为显示，赋0为隐藏
//   SetConsoleCursorInfo(hOut,&cci);
// }
// void gotoxy(int x,int y) //移动坐标
// {
//     COORD coord;
//     coord.X=x;
//     coord.Y=y;
//     SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
// }

// int main()
// {
//     hidden_cursor();
//     srand(time(NULL));
//     system("chcp 65001");
//     system("cls");
//     int ccc=rand()%6+1;
//     printf("Welcome to the game!\nDo you want to start?(Y/n)");
//     getch();
// 	add();
//     while(1)
//     {
//         int dx=0;
//         bool rotate=0;
//         bool speed=0;
//         system("cls");
//         // clrscr();
//         if(kbhit())
//         {
//             char dir=getch();
//             switch(dir)
//             {
//                 case 'a':
//                 case 'A':
//                     dx=-1;
//                     break;
//                 case 'd':
//                 case 'D':
//                     dx=1;
//                     break;
//                 case 'w':
//                 case 'W':
//                     rotate=1;
//                     break;
//                 case 'S':
//                 case 's':
//                     speed=1;
//                     break;
//                 default:
//                     break;
//             }
//         }
//         for(int i=0;i<4;i++)
//         {
//             pre[i]=cur[i];
//             cur[i].x+=dx;
//         }
//         if(check())
//         {
//             for(int i=0;i<4;i++)
//             {
//                 cur[i]=pre[i];
//             }
//         }
//         if(rotate)
//         {
//             for(int i=0;i<4;i++)
//             {
//                 pre[i]=cur[i];
//                 int tx=cur[i].x-cur[1].x;
//                 int ty=cur[i].y-cur[1].y;
//                 cur[i].x=ty+cur[1].x;
//                 cur[i].y=-tx+cur[1].y;
//             }
//             if(check())
//             {
//                 for(int i=0;i<4;i++)
//                 {
//                     cur[i]=pre[i];
//                 }
//             }
//         }
//         long long now=GetTickCount();
//         int tick;
//         if(speed==1)
//         {
//             tick=300;
//         }
//         else
//         {
//             tick=50;
//         }
        
//         if(now-LastTick>tick)
//         {
//             for(int i=0;i<4;i++)
//             {
//                 pre[i]=cur[i];
//                 cur[i].y+=1;
//             }
//             LastTick=now;
//             if(check())
//             {
//                 for(int i=0;i<4;i++)
//                 {
//                     cur[i]=pre[i];
//                     fields[cur[i].x][cur[i].y]=1;
//                 }
//                 add();
//             }
//         }
//         int k=M-1;
//         for(int i=N-1;i>=0;i--)
// 		{
// 			int cnt=0;
// 			for(int j=0;j<M;j++)
// 			{
// 				if(fields[j][i]) cnt++;
// 				fields[j][k]=fields[j][i];
// 			}
// 			if(cnt!=M)
// 			{
// 				k--;
// 			}
// 		}
//         color(ccc);
//         for(int i=0;i<4;i++)
//         {
//             gotoxy(cur[i].x*2,cur[i].y);
//             printf("■");
//         }
//         for(int i=0;i<M;i++)
//         {
//             for(int j=0;j<N;j++)
//             {
//                 if(fields[i][j]!=0)
//                 {
//                     gotoxy(i*2,j);
//                     printf("■");
//                 }
//             }
//         }
//         Sleep(200);
//     }
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
vector <int> G[100];
int dfn[100];
int low[100];
int vis[100];
int color[100];
int ct=0;
int n;
stack<int> s;
void dfs(int x)
{
    ct++;
    dfn[x]=ct;
    low[x]=ct;
    for(int i=0;i<G[x].size();i++)
    {
        int to=G[x][i];
        if(dfn[to]==0)
        {
            dfs(to);
            low[x]=min(low[x],low[to]);
        }
        else if(vis[to]==1)
        {
            low[x]=min(low[x],low[to]);
        }
    }
    if(dfn[x]==low[x])
    {
        int now;
        do{
            now=s.top();
            s.pop();
            color[now]=x;
            vis[now]=0;
        }while(now!=x);
    }
}
vector<int> newG[100];
void buildnew()
{
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<G[i].size();j++)
        {
            int to=G[i][j];
            if(color[i]!=color[j])
            {
                newG[color[i]].push_back(color[j]);
            }
        }
    }
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        int a,b;
        cin>>a>>b;
        G[a].push_back(b);
    }
    for(int i=1;i<=n;i++)
    {
        if(dfn[i]==0)
        {
            dfs(i);
        }
    }
    for(int i=0;i<ct;i++)
    {
        cout<<dfn[i];
    }
    return 0;
}