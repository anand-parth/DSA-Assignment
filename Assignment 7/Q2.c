#include<stdio.h>
#include<stdlib.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)

#define pn() printf("\n");
#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)

int n;
int arr[100][100], vis[100], ar[100][100];
int stack[100], top = 0;
int comp[100], ct = 0;
void push(int x)
{
	stack[top++] = x;
}
int pop()
{
	return stack[top--];
}
void SCC(int src)
{
	vis[src] = 1;
	for(int i=0;i<n;i++)
	{
		if(arr[src][i] == 1 && vis[i] != 1)
		{
			SCC(i);
		}
	}
	push(src);
}
void dfs(int src)
{
	vis[src] = 1;
	comp[src] = ct;
	for(int i=0;i<n;i++)
	{
		if(ar[src][i] == 1 && vis[i] != 1)
		{
			dfs(i);
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
	int distance[n][n];
	loop(i,n)
	loop(i,n)
	{
		if(vis[i] != 1)
			SCC(i);
	}
	pop();
	loop(i,n)
	{
		loop(j,n)
		{
			ar[i][j] = 0;
		}
	}
	loop(i,n)
	{
		loop(j,n)
		{
			if(arr[i][j] == 1)
				ar[j][i] = 1;
		}
	}
	loop(i,n)
		vis[i] = 0;
	while(top != -1)
	{
		int val = pop();
		if(vis[val] != 1)
		{
			ct++;
			dfs(val);
		}
	}
	int sum = 0;
	int gm = 1; 
	for(int i=1;i<=ct;i++)
	{
		int min = 9999;
		int mincount = 1;
		for(int j=0;j<n;j++)
		{
			if(comp[j] == i)
			{
				if(a[j] < min)
				{
					mincount = 1;
					min = a[j];
				}
				else if(a[j] == min)
					mincount++;
			}
		}
		gm= gm * mincount;
		sum = sum + min;
	}
	print2(sum,gm);
	
	return 0;
}