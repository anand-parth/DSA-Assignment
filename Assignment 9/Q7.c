#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)
#define pn() printf("\n");

#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)
// #define loop(i,a,n) for(int i=a;i<n;i++)

#define max(a,nb) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int a[100][100];
int vis[100];
int n;
int mincost = 9999;
void dfs(int s, int d, int k, int level, int cost)
{
	if(level > k+1)
	{
		vis[s] = 0;
		return;
	}
	if(s == d)
	{
		if(cost < mincost)
			mincost = cost;
		vis[s] = 0;
		return ;
	}
	loop(i,n)
	{
		if(a[s][i] > 0 && vis[i] != 1)
		{
			dfs(i,d,k,level+1,cost+a[s][i]);
		}
	}
}
int main()
{
	int m;
	scan2(n,m);
	loop(i,m)
	{

		int u,v,price;
		scan3(u,v,price);
		a[u][v] = price;
	}
	int t;
	scan1(t);
	loop(i,t)
	{
		int s, d, k;
		scan3(s,d,k);
		dfs(s,d,k,0,0);
		if(mincost == 9999)
			printf("Not possible\n");
		else
			print1(mincost);
		mincost = 9999;
		loop(j,n)
			vis[i] = 0;
	}
	return 0;
}