#include<bits/stdc++.h>
using namespace std;
int gcd1(int x,int y)//µÝ¹é·¨ 
{
	if(!y)
		return x;
	else
		return gcd1(y,x%y);
}
int gcd2(int a,int b)//Ñ­»··¨ 
{
	int t;
	if(a<b)
	{
		swap(a,b);
	}
	while(b)
	{
		t=b;
		b=a%b;
		a=t;
	}
	return a;
}
int gcd3(int a,int b)
{
	int t;
	while(b)
	{
		if(a<b)
		{
			swap(a,b);
		}
		t=a-b;
		a=b;
		b=t;
	}
	return a;
}
int main()
{
	int n,m,t;
	scanf("%d%d",&n,&m); 
	printf("%d\n%d\n%d",gcd1(n,m),gcd2(n,m),gcd3(n,m));
	return 0;
} 
