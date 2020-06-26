#include<bits/stdc++.h>
using namespace std;
void shiftdown(int i);
void push(int i);
void pop();
//void dfs(int i);
int front();
int hp[100],len=1;
void push(int i)
{
    hp[len]=i;
    int child=len,parent=len>>1;
    while(parent>0&&hp[parent]<i)
    {
        hp[child]=hp[parent];
        child=parent;
        parent=child>>1;
    }
    hp[child]=i;
    len++;
}
void shiftdown(int i)
{
    int t=hp[i];
    int child=i<<1,parent=i;
    while(child<len)
    {
        if(child+1<len&&hp[child]<hp[child+1])
        {
            child|=1;
        }
        if(t>hp[child])
        {
            break;
        }
        hp[parent]=hp[child];
        parent=child;
        child=parent<<1;
    }
    hp[parent]=t;
    return;
}
void pop()
{
    hp[1]=hp[len-1];
    len--;
    shiftdown(1);
    return;
}
int front()
{
    return hp[1];
}
void heap(int a[],int size)
{
    memcpy(hp+1,a,size*sizeof(int));
    
    len=size+1;
    for(int i=(len-1)>>1;i>=1;i--)
    {
        shiftdown(i);
    }
    return;
}
/*
void dfs(int i)
{
    if(i>len)
    {
        return;
    }
    dfs(i<<1);
    dfs(i<<1|1);
    printf("%d,",hp[i]);
    return;
}
*/
int main()
{
    int a[]={4,2,8,3,9};
    heap(a,5);
    push(12);
    for(int i=0;i<5;i++)
    {
        printf("%d,",front());
        pop();
    }
    return 0;
}