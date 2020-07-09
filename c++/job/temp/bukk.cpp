//p1015
#include<bits/stdc++.h>
const int S=303;
int n,a[S],l;
char c[S],d[S];
inline void add()
{
	for (int i=0;i<l;++i)
		d[l-i-1]=c[i];
	l+=2;
	for (int i=0;i<l;++i)
	{
		c[i]+=d[i];
		if (c[i]>=n) c[i+1]++,c[i]-=n;
	}
	while (!c[l-1]) --l;
}
inline bool pd()
{
	for (int i=0;i<l;++i)
		if (c[i]!=c[l-1-i]) return false;
	return true;
}
int main()
{
	scanf("%d%s",&n,c);l=strlen(c);
	for (int i=0;i<l;++i)
	{
		if (c[i]>='0' && c[i]<='9') c[i]-='0';
		else c[i]=c[i]-'A'+10;
	}
	int step=0;
	while (!pd())
	{
		++step;
		if (step>30) break;
		add();
	}
	if (step<=30) printf("STEP=%d\n",step);
	else puts("Impossible!");
	return 0;
}