#include <bits/stdc++.h>
const int size = 10000;
int p[size], v[size]; //p为记录质数,v为标记质数
int cnt, n,t;
int main()
{
    scanf("%d",&n);
    v[0]=v[1]=1;
    for (int i = 2; i <= n; i++)
    {
        if (!v[i]) //如果i为质数
        {
            p[++cnt] = i; //记录质数
        }
        for (int j = 1; j <= cnt && i *p[j]<=n; j++)
        {
            v[i * p[j]] = 1; //标记已找到的质数
            if (i % p[j] == 0)
            {
                break;
            }
        }
    }
    for(int i=2;i<=n;i++)
    {
        if(!v[i])
        {
            printf("%d,",i);
        }
    }
    return 0;
}