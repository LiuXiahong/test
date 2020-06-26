#include<bits/stdc++.h>
using namespace std;
int a[10]={0,2,3,3,4,5},b[10]={0,200,300,350,400,500},dp[11]={0};

int main()
{
	for(int i=1;i<=5;i++)
	{
		for(int j=10;j>=a[i];j--)
		{
			dp[j]=max(dp[j],dp[j-a[i]]+b[i]);
		}
		for(int j=0;j<=10;j++)
			printf("%d ",dp[j]);
		printf("\n");
	}
	/*
	for(int i=1;i<=5;i++)
	{
		for(int j=0;j<=10;j++)
		{
			if(j>=a[i])
			{
				dp[i][j]=max(dp[i-1][j],dp[i-1][j-a[i]]+b[i]);
			}
			else
			{
				dp[i][j]=dp[i-1][j];
			}
			printf("%d ",dp[i][j]);
		}
		printf("\n");
	}
	*/
	printf("%d",dp[10]);
}
