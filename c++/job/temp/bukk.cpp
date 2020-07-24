//P5723 【深基4.例13】质数口袋
#include <bits/stdc++.h>
using namespace std;
int n, t;
long long sum = 0;
int f(int x)
{
	for (int i = 2; i * i <= x; i++)
	{
		if (x % i == 0)
		{
			return 0;
		}
	}
	return 1;
}
int main()
{
	scanf("%d", &n);
	if (n < 2)
	{
		printf("0\n");
		return 0;
	}
	else if (n == 2)
	{
		printf("2\n1\n");
		return 0;
	}
	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0 && i != 2)
			continue;
		if (sum + i > n)
		{
			printf("%d\n", t);
			return 0;
		}
		if (f(i))
		{
			printf("%d\n", i);
			sum += i;
			t++;
		}
	}
	return 0;
}