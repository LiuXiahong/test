#include<string>
#include<map>
#include<iostream>
using namespace std;
//0-R  1-s  2-p
string rr[3][3]={
	                {"Tie","Player1","Player2"},
	                {"Player2","Tie","Player1"},
	                {"Player1","Player2","Tie"}
                };
map<string,int> m;
int main()
{
	m["Rock"]=0,m["Scissors"]=1,m["Paper"]=2;
	string p1,p2;
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>p1>>p2;
		cout<<rr[m[p1]][m[p2]]<<endl;
	}
}
