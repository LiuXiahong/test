#include <bits/stdc++.h>
using namespace std;
int n, m, user_map[1505][1505], sum, xx[1505 * 1505], mann;
int dnext[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
char c;
void dfs(int x, int y)
{
     user_map[x][y] = 0;
    sum++;
    for (int i = 0; i < 8; i++)
    {
        int xx = x + dnext[i][0], yy = y + dnext[i][1];
        if (xx > 0 && xx <= n && yy > 0 && yy <= m &&  user_map[xx][yy])
            dfs(xx, yy);
    }
}
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> c;
            if (c == '.')
                 user_map[i][j] = 0;
            if (c == '*')
                 user_map[i][j] = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if ( user_map[i][j] == 1)
            {
                dfs(i, j);
                xx[sum]++;
                if (sum * xx[sum] > mann)
                    mann = sum * xx[sum];
                sum = 0;
            }
        }
    }
    int ans = 0;
    for (int i = 0; i <= n * m; i++)
    {
        if (xx[i])
            ans++;
    }
    cout << ans << ' ' << mann;
    return 0;
}