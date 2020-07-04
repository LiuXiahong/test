#include<bits/stdc++.h>
using namespace std;
int book[100001]={0};
int n,m,l,r,t;
int ans1,ans2;
int main()
{
    cin>>n>>m;
    for(int i=0;i<=n;i++)
    {
        book[i]=1;
    }
    for(int i=1;i<=m;i++)
    {
        cin>>t>>l>>r;
        if(t==0)
        {
            for(int j=l;j<=r;j++)
            {                 
                
                if(book[j]==2)
                {
                    ans2++;
                }
                book[j]=0;
            }
        }
        if(t==1)
        {
            for(int j=l;j<=r;j++)
            {
                if(book[j]==0)
                {
                    book[j]=2;
                }
            }
        }
    }
    for(int i=0;i<=n;i++)
        if(book[i]==2)
            ans1++;
    cout<<ans1<<endl<<ans2;
}
    //校门外马路上本来从编号0到L，每一编号的位置都有1棵树。
    //有砍树者每次从编号A到B处连续砍掉每1棵树，就连树苗也不放过（记 0 A B ，含A和B）；
    //幸运的是还有植树者每次从编号C到D 中凡是空穴（树被砍且还没种上树苗或树苗又被砍掉）
    //的地方都补种上树苗（记 1 C D，含C和D）；
    //问最终校门外留下的树苗多少棵？植树者种上又被砍掉的树苗有多少棵？
