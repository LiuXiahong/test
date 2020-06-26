#include<stdio.h>
int main()
{
	int n;
	scanf("%d",&n);
	system("space");
	for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=n-i;j++)
			printf(" ");
		for(int m=0;m<=2*i;m++)
			printf("*");
		printf("\n");
	}
}
