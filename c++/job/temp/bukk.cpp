/*
#include<bits/stdc++.h>
using namespace std;
int a[6]={0,2,1,5,7,9},dir[10],sum[10],s;
int x[3]={2,3,1},y[3]={4,5,3},z[3]={2,-3,5};
int main()
{
    for(int i=0;i<6;i++)
    {
        dir[i]=a[i]-a[i-1];
        cout<<dir[i]<<' ';
    }
    cout<<endl;
    for(int i=0;i<3;i++)
    {
        dir[x[i]]+=z[i];
        dir[y[i]]-=z[i];
    }
    for(int i=0;i<6;i++)
    {
        s+=dir[i];
        cout<<s<<' ';
        sum[i]=sum[i-1]+s;
    }
    printf("%d/n%d/n%d/n%d/n",sum[4]-sum[1],sum[5]-sum[2],sum[])
    return 0;
}
*/

/*
2-4 +3
1-7 -5
Q 5
4-9 +2
3-8 -7
Q 3
Q 8
6-10 +5
Q 7
*/
#include<bits/stdc++.h>
using namespace std;
int a[11]={0,2,1,5,7,9},dir[11],sum[11],s;
int x[5]={2,1,4,3,6},
    y[5]={4,7,9,8,10},
    z[5]={3,-5,2,-7,5};
int main()
{
    for(int i=1;i<=11;i++)
    {
        dir[i]=a[i]-a[i-1];
        //cout<<dir[i]<<' ';
    }
    //cout<<endl;
    dir[x[0]]+=z[0];
    dir[y[0]]-=z[0];
    dir[x[1]]+=z[1];
    dir[y[1]]-=z[1];
    for(int i=1;i<=11;i++)
    {
        s+=dir[i];
        sum[i]=sum[i-1]+s;
    }
    cout<<sum[6]-sum[5]<<' ';
    dir[x[2]]+=z[2];
    dir[y[2]]-=z[2];
    dir[x[3]]+=z[3];
    dir[y[3]]-=z[3];
    for(int i=1;i<=11;i++)
    {
        s+=dir[i];
        sum[i]=sum[i-1]+s;
    }
    cout<<sum[4]-sum[3]<<' ';
    cout<<sum[9]-sum[8]<<' ';
    dir[x[4]]+=z[4];
    dir[y[4]]-=z[4];
    for(int i=1;i<=11;i++)
    {
        s+=dir[i];
        sum[i]=sum[i-1]+s;
    }
    cout<<sum[10]-sum[9]<<' ';
    return 0;
}