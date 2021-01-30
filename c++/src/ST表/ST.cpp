// #include<bits/stdc++.h>
// using namespace std;
// struct node
// {
//     int l,r,v;
// }tree[1000];
// int a[1000]={0,1,2,3,4,5,6,7,8,9};
// void build(int p,int l,int r)//建线段树
// {
//     tree[p].l=l;
//     tree[p].r=r;
//     if(r==l)
//     {
//         tree[p].v=a[l];
//         return;
//     }
//     int mid=(l+r)>>1;
//     build(p<<1,l,mid);
//     build(p<<1|1,mid+1,r);
//     tree[p].v=tree[p<<1].v+tree[p<<1|1].v;
// }
// void update(int p,int idx,int v)//修改idx号元素为v
// {
//     if(tree[p].l==tree[p].r)
//     {
//         tree[p].v=v;
//         return;
//     }
//     if(idx<=tree[p<<1].r)
//     {
//         update(p<<1,idx,v);
//     }
//     else
//     {
//         update(p<<1|1,idx,v);
//     }
//     tree[p].v=tree[p<<1].v+tree[p<<1|1].v;
//     return;   
// }
// int query(int p,int l,int r)//查询l-r区间的和
// {
//     if(tree[p].l>=l&&tree[p].r<=r)
//     {
//         return tree[p].v;
//     }
//     if(tree[p].l>r||tree[p].r<l)
//     {
//         return 0;
//     }
//     int s=0;
//     if(tree[p<<1].r>=l)
//     {
//         s+=query(p<<1,l,r);
//     }
//     if(tree[p<<1].l<=r)
//     {
//         s+=query(p<<1|1,l,r);
//     }
//     return s;
// }
// int main()
// {
//     build(1,1,10);
//     cout<<query(1,4,10)<<endl;
//     update(1,8,5);
//     cout<<query(1,4,10);
//     return 0;
// }

#include<bits/stdc++.h>
using namespace std;
int a[100]={0,1,2,3,4,5,6,7,8,9,10};
struct node{
	int l,r,v;
	int tag;//懒标记
};
node tree[1000];
void build(int p,int l,int r)
{
	tree[p].l=l;
	tree[p].r=r;
	if(r==l)
	{
		tree[p].v=a[l];
		return ;
	}
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
	tree[p].v=tree[p<<1].v+tree[p<<1|1].v;
	
}

void update(int p,int l,int r,int v)
{
	if(tree[p].l>=l&&tree[p].r<=r)
	{
		tree[p].tag+=v;
		tree[p].v+=(tree[p].r-tree[p].l+1)*v;
		return ;
	}
	if(tree[p].l>r||tree[p].r<l) return ;
	//下推 
	tree[p<<1].tag+=tree[p].tag;
	tree[p<<1].v+=(tree[p<<1].r-tree[p<<1].l+1)*tree[p].tag;
	tree[p<<1|1].tag+=tree[p].tag;
	tree[p<<1|1].v+=(tree[p<<1|1].r-tree[p<<1|1].l+1)*tree[p].tag;
	tree[p].tag=0;
	
	if(l<=tree[p<<1].r)
	{
		update(p<<1,l,r,v);
	}
	if(tree[p<<1|1].l<=r)
	{
		update(p<<1|1,l,r,v);
	}
	tree[p].v=tree[p<<1].v+tree[p<<1|1].v;
}

int query(int p,int l,int r)
{
	if(tree[p].l>=l&&tree[p].r<=r)
	{
		return tree[p].v;
	}
	if(tree[p].l>r||tree[p].r<l) return 0;
	//下推 
	tree[p<<1].tag+=tree[p].tag;
	tree[p<<1].v+=(tree[p<<1].r-tree[p<<1].l+1)*tree[p].tag;
	tree[p<<1|1].tag+=tree[p].tag;
	tree[p<<1|1].v+=(tree[p<<1|1].r-tree[p<<1|1].l+1)*tree[p].tag;
	tree[p].tag=0;
	
	int s=0;
	if(tree[p<<1].r>=l)
	{
		s+=query(p<<1,l,r);
	}
	if(tree[p<<1|1].l<=r)
	{
		s+=query(p<<1|1,l,r);
	}
	return s;
}

int main()
{
	build(1,1,10);
	printf("%d\n",query(1,4,10));
	update(1,8,9,2);
	printf("%d",query(1,4,10));
}