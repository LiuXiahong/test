#include<bits/stdc++.h>
using namespace std;
int a[6]={0,2,1,5,7,9},dir[10],sum[10],s;
int x[3]={2,3,1}/*左区间*/,y[3]={4,5,3}/*右区间*/,z[3]={2,-3,5};/*指定数目*/
int main()
{
    for(int i=0;i<6;i++)//创建差分数组
    {
        dir[i]=a[i]-a[i-1];
        cout<<dir[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<3;i++)//在左右区间节点＋/-指定数
    {
        dir[x[i]]+=z[i];
        dir[y[i]]-=z[i];
    }
    for(int i=0;i<6;i++)//前缀和
    {
        s+=dir[i];
        cout<<s<<' ';
        sum[i]=sum[i-1]+s;
    }
    printf("%d/n%d/n",sum[4]-sum[1],sum[5]-sum[2]);//输出
    return 0;
}