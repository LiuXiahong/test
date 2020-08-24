#include<bits/stdc++.h>
using namespace std;
int dix[101],f[101][5001];
int n,m,sum,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>dix[i];
        ans+=dix[i];
    }
    sum=ans/2;
    m=n/2;
    f[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=min(i,m);j>=1;j--)
        {
            for(int k=sum;k>=dix[i];k--)
            {
                f[j][k]=f[j][k]||f[j-1][k-dix[i]];
            }
        }
    }
    for(int i=sum;i;i--)
    {
        if(f[m][i])
        {
            cout<<i;
            return 0;
        }
    }
}