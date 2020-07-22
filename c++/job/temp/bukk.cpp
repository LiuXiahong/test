/* 
//P5712 【深基3.例4】Apples
#include<bits/stdc++.h>
using namespace std;
int n,a,b;
int main()
{
	cin>>n;
	a=5*n;
	b=11+3*n;
	if(a>b)
	return 0;
}
*/
//P1090 合并果子 / [USACO06NOV] Fence Repair G
#include<bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > p;
int n,t;
int ans,a,b;
int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		p.push(t);
	}
	while(p.size()>=2)
	{
		a=p.top();
		p.pop();
		b=p.top();
		p.pop();
		ans+=a+b;
		p.push(a+b);
	}
	cout<<ans;
	return 0;
}
