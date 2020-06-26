#include<bits/stdc++.h>
using namespace std;
char a[10000];
int ans[10000]={0};
int n;
int main()
{
	cin>>a>>n;
	int len=strlen(a);
	for(int i=0;i<len;i++)
	{
		ans[i]=a[i]-'0';
	}
	int l=0;
	int t=0;
	for(int i=0;i<len;i++)
	{
		l+=ans[i];
		if((l/n)==0)
		{
			if(t)
				printf("0");
			l*=10;
		}
		else
		{
			printf("%d",l/n);
			l=(l%n)*10;
			t=1;
		}
	}
	printf(" mod %d",l/10);
}
