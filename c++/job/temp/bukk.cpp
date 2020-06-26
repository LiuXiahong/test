#include<bits/stdc++.h>
using namespace std;
const int MAX = 30;
int sq[MAX][MAX][MAX] = {0};
int a,b,c,n,ans;
int main()
{
	cin>>a>>b>>c>>n;
	while(n--)
	{
		int x1,y1,z1,x2,y2,z2;
		cin>>x1>>y1>>z1>>x2>>y2>>z2;
		for(int i = x1;i <= x2;i++)
        {
			for(int j = y1;j <= y2;j++)
            {
				for(int k = z1;k <= z2;k++) sq[i][j][k] = 1;
            }
        }
	}
	for(int i = 1;i <= a;i++)
    {
		for(int j = 1;j <= b;j++)
        {
			for(int k = 1;k <= c;k++)
            {
				if(sq[i][j][k] == 0) ans++; 
            }
        }
    }
	cout<<ans<<endl; 
	return 0;
} 