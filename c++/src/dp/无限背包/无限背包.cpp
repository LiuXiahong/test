#include<bits/stdc++.h>
using namespace std;
int a[10]={0,3,3,4,5,5},b[10]={0,200,300,350,400,500},dp[11]={0};
int main()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=a[i];j<=10;j++)
		{
			for(int k=0;k<=j/a[i];k++)
			{
				dp[j]=max(dp[j],dp[j-k*a[i]]+k*b[i]);
			}
            printf("%d ",dp[j]);
		}
		printf("\n");
	}
	printf("%d",dp[10]);
 } 
