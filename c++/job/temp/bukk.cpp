//P5720 �����4.��4��һ��֮�
#include<bits/stdc++.h>
using namespace std;
int n,i;
int main()
{
	cin>>n;
	while(n!=1)
	{
		i++;
		n/=2;
	}
	cout<<i+1;
	return 0;
}