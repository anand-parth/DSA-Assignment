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

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int mincost = 9999;
int n;
int a[100][100];
void dfs(int i, int j, int cost,int v[n][n],int h)
{
	int vis[n][n];
	loop(l,n)
	{
		loop(k,n)
		{
			vis[l][k] = v[l][k];
		}
	}
	vis[i][j] =1;
	if(i == n-1 && j == n-1)
	{
		if(cost < mincost)
			mincost = cost;
		return ;
	}
	else
	{
		if(i != 0 && !vis[i-1][j])
		{
			if(h > a[i-1][j])
				dfs(i-1,j,cost,v,h);
			else
				dfs(i-1,j, cost+a[i-1][j] - h,vis,a[i-1][j]);
		}
		if(i != n-1 && !vis[i+1][j])
		{
			if(h > a[i+1][j])
				dfs(i+1,j,cost,v,h);
			else
				dfs(i+1,j, cost+a[i+1][j] - h,vis,a[i+1][j]);
		}
		if(j != 0 && !vis[i][j-1])
		{
			if(h > a[i][j-1])
				dfs(i,j-1,cost,v,h);
			else
				dfs(i,j-1, cost+a[i][j-1] - h,vis,a[i][j-1]);
		}
		if(j != n-1 && !vis[i][j+1])
		{
			if(h > a[i][j+1])
				dfs(i,j+1,cost,v,h);
			else
				dfs(i,j+1, cost+a[i][j+1] - h,vis,a[i][j+1]);	
		}
	}
}

int main()
{
	scan1(n);	
	loop(i,n)
	{
		loop(j,n)
		{
			scan1(a[i][j]);
		}
	}
	int vis[n][n];
	loop(i,n)
	{
		loop(j,n)
		{
			vis[i][j] =  0;
		}
	}
	dfs(0,0,0,vis,a[0][0]);
	print1(mincost+a[0][0]);
	return 0;
}