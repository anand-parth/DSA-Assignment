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

int n;
int arr[100][100], vis[100];
int stack[100];
int top = 0;
int ar[100][100];
void dfs(int src, int og)
{
	vis[src] = 1;
	for(int i=0;i<n;i++)
	{
		if(arr[src][i] == 1 && vis[i] != 1)
		{
			ar[og][i] = 1;
			dfs(i,og);
		}
	}
}
void SCC(int src)
{
	vis[src] = 1;
	for(int i=0;i<n;i++)
	{
		if(ar[src][i] == 1 && ar[i][src] == 1)
		{
			push(i);
			SCC(i);
		}
	}
}
int main()
{

	scan1(n);
	int a[n];
	loop(i,n)
		scan1(a[i]);
	int m;
	scan1(m);
	loop(i,m)
	{
		int u,v;
		scan2(u,v);
		arr[u-1][v-1] = 1;
	}
	loop(i,n)
	{
		loop(j,n)
			ar[i][j] = 0;
	}
	loop(j,n)
	{
		loop(i,n)
			vis[i] = 0;
		dfs(j,j);
	}

	loop(i,n)
	{
		for(int j=i+1;j<n;j++)
		{
			if(ar[i][j] == 1 && ar[i][j] == ar[j][i])
				print2(i,j);
		}
	}
	loop(i,n)
	{
		if(!vis[i])
			push(i);
	}
	
	return 0;
}
		