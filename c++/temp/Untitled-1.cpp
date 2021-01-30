#include<stdio.h>
#include<windows.h>
#include<conio.h>
#include<time.h>
const int M=10,N=20;
void gotoxy(int x,int y) //移动坐标
{
    COORD coord;
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition( GetStdHandle( STD_OUTPUT_HANDLE ), coord );
}

int color(int c)
{
    switch(c)
    {
    case 0: c=9;break;
    case 1:
    case 2: c=12;break;
    case 3:
    case 4: c=14;break;
    case 5: c=10;break;
    case 6: c=13;break;
    default: c=7;break;
    }
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), c);        //更改文字颜色
    return 0;
}
void hidden_cursor()//隐藏光标
{
  HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_CURSOR_INFO cci;
  GetConsoleCursorInfo(hOut,&cci);
  cci.bVisible=0;//赋1为显示，赋0为隐藏
  SetConsoleCursorInfo(hOut,&cci);
}
int elements[7][4]={
	2,3,4,5,
	1,3,5,7,
	2,4,5,7,
	3,5,4,6,
	3,5,7,6,
	2,4,6,7,
	3,5,4,7
};
struct Point{
	int x,y;
};
Point cur[4],pre[4];
long long lastTick;
int fields[M][N];
int check()
{
	for(int i=0;i<4;i++)
	{
		if(cur[i].x<0||cur[i].x>=M||cur[i].y>=N) return 1;
		if(fields[cur[i].x][cur[i].y]) return 1;
	}
	return 0;
}

int main()
{
	hidden_cursor();
	srand(time(NULL)); 
	int num=rand()%7;
	int ccc=rand()%6+1;
	for(int i=0;i<4;i++)
	{
		cur[i].x=elements[num][i]%2;
		cur[i].y=elements[num][i]/2;
	}
	while(1)
	{
		system("cls");
		int dx=0;
		bool rotate=false;
		bool speed=false;
		if(kbhit())
		{
			char dir=getch();
			switch(dir)
			{
				case 'a':
				case 'A':
					dx=-1;
					break;
				case 'd':
				case 'D':
					dx=1;
					break;
				case 'w':
				case 'W':
					rotate=true;
					break;
				case 's':
				case 'S':
					speed=true;
				default:
					break;
			}
		}
		
		for(int i=0;i<4;i++)
		{
			pre[i]=cur[i];
			cur[i].x+=dx;
		}
		if(check())
		{
			for(int i=0;i<4;i++) cur[i]=pre[i];
		}
		
		if(rotate)
		{
			for(int i=0;i<4;i++)
			{
				pre[i]=cur[i];
				int tx=cur[i].x-cur[1].x;
				int ty=cur[i].y-cur[1].y;
				cur[i].x=ty+cur[1].x;
				cur[i].y=-tx+cur[1].y;
			}
			if(check())
			{
				for(int i=0;i<4;i++) cur[i]=pre[i];
			}
		}
		
		long long now=GetTickCount();//
		int tick;
		if(speed==true)
		{
			tick=50;
		}
		else
		{
			tick=300;
		}
		if(now-lastTick>tick)
		{
			for(int i=0;i<4;i++)
			{
				pre[i]=cur[i];
				cur[i].y+=1;
			}
			lastTick=now;
			if(check())
			{
				for(int i=0;i<4;i++)
				{
					cur[i]=pre[i];
					fields[cur[i].x][cur[i].y]=ccc;
				}
				int num=rand()%7;
				ccc=rand()%6+1;
				for(int i=0;i<4;i++)
				{
					cur[i].x=elements[num][i]%2;
					cur[i].y=elements[num][i]/2;
				}
			}
		}
		
		int k=N-1;
		for(int i=N-1;i>=0;i--)
		{
			int ct=0;
			for(int j=0;j<M;j++)
			{
				if(fields[j][i]) ct++;
				fields[j][k]=fields[j][i];
			}
			if(ct!=M)
			{
				k--;
			}
		}
		color(ccc);
		for(int i=0;i<4;i++)
		{
			gotoxy(cur[i].x*2,cur[i].y);
			printf("■");
		}
		for(int i=0;i<M;i++)
		{
			for(int j=0;j<N;j++)
			{
				if(fields[i][j]!=0)
				{
					color(fields[i][j]);
					gotoxy(i*2,j);
					printf("■");
				}
			}
		 } 
		//Sleep(200);
	}
}