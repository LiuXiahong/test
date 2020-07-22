//P5710 【深基3.例2】数的性质
#include<bits/stdc++.h>
using namespace std;
int n;
bool a,b;
int main()
{
	cin>>n;
	a=(n%2==0);
	b=n>4&&n<=12;
	cout << (a && b) << " " << (a || b) << " " << ((a == 1 && b == 0) || (a == 0 && b == 1)) << " " << (!a && !b) << endl;
	return 0;
}