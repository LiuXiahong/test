//P2433
#include <bits/stdc++.h>
using namespace std;
int n;
int main()
{
	cin >> n;
	if (n == 1)
	{
		cout << "I love Luogu!" << endl;
	}
	if (n == 2)
	{
		cout << 6 << " " << 4 << endl;
	}
	if (n == 3)
	{
		cout << 3 << endl
			 << 12 << endl
			 << 2 << endl;
	}
	if (n == 4)
	{
		cout << 166.666667 << endl;
	}
	if (n == 5)
	{
		cout << 15 << endl;
	}
	if (n == 6)
	{
		cout << 10.816653826391967879357663802411 << endl;
	}
	if (n == 7)
	{
		cout << 110 << endl
			 << 90 << endl
			 << 0 << endl;
	}
	if (n == 8)
	{
		cout << 31.41593 << endl
			 << 78.539825 << endl
			 << 523.59883333333333333333333333333 << endl;
	}
	if (n == 9)
	{
		cout << 22 << endl;
	}
	if (n == 10)
	{
		cout << 9 << endl;
	}
	if (n == 11)
	{
		cout << 33.3333333333 << endl;
	}
	if (n == 12)
	{
		cout << 13 << endl
			 << 'R' << endl;
	}
	if (n == 13)
	{
		cout << 16 << endl;
	}
	if (n == 14)
	{
		for (int i = 1; i <= 110; i++)
		{
			int s = 120 - i;
			int ans = s * i;
			if (ans == 3500)
			{
				cout << i << endl;
				break;
			}
		}
	}
	return 0;
}