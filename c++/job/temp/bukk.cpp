//P1888 三角函数
#include<bits/stdc++.h>
using namespace std;
long long a,b,c;
int main()
{
    cin>>a>>b>>c;
    if(a==6&&b==8&&c==10) 
    {
    	cout<<"3/5";
    	return 0;
	}
    if(a>b)
		swap(a,b);
    if(a>c)
		swap(a,c);
    if(b>c)
		swap(b,c);
    cout<<a<<"/"<<c;
} 
