//[NOI Online #3 入门组]最急救助
//相关链接🔗 https://www.luogu.com.cn/problem/P6565
#include<bits/stdc++.h>
using namespace std;
int n,ans,maxn;
string name,dix;
string v[205];
int a[205];
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        ans=0;
        cin>>name>>dix;
        int len=dix.size();//考试的时候没找到问题,只有70分😥
        for(int j=0;j<len-2;j++)
        {
            if(dix[j]=='s'&&dix[j+1]=='o'&&dix[j+2]=='s')
            {
                ans++;
            }
        }
        maxn=max(maxn,ans);
        v[i]=name;
        a[i]=ans;
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]==maxn)
        {
            cout<<v[i]<<' ';
        }
    }
    cout<<endl<<maxn;
    return 0;
}