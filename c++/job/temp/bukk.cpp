#include<bits/stdc++.h>
using namespace std;
int dir[21][21],n;
int main()
{
    cin>>n;
    for (int i = 1; i <= n; i++)
        dir[i][1] = dir[i][i] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 2; j < i; j++)
            dir[i][j] = dir[i - 1][j] + dir[i - 1][j - 1];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            printf("%d ", dir[i][j]);
        printf("\n");
    }
}