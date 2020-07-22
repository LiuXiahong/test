//P5711 【深基3.例3】闰年判断
#include<bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin>>n;
	printf("%d",(n%4==0)&&(n%100!=0)||(n%400==0));
	return 0;
}