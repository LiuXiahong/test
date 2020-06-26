#include<bits/stdc++.h>
const int size=3;
struct queue
{
	int q[10000],head,tail;
	void push(int a)//压入
	{
		if((tail+1)%size==head)
		{
			printf("Full\n");
			return;
		}
		q[tail]=a;
		tail=(tail+1)%size;
		return;
	}
	void pop()//弹出
	{
		if(head==tail)
		{
			printf("Empty\n");
			return;
		}
		head=(head+1)%size;
	}
	int front()//返回顶部元素
	{
		return q[head];
	}
	bool empty()//是否为空
	{
		return head==tail;
	}
}s;
int main()
{
	s.push(1);
	s.push(2);
	printf("%d\n",s.front());
	printf("%d\n",s.front());
	s.pop();
	printf("%d\n",s.front());
	s.pop();
	s.push(3);
	s.push(4);
	printf("%d\n",s.front());
	s.pop();
}
