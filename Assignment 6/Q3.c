#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)

#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)
// #define loop(i,a,n) for(int i=a;i<n;i++)
int adj[100][100];
int a[100];
int n,m;
int ans = 0;
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

void dfs(int curr, int meow,int dest, int *v)
{
	int visited[n];
	loop(i,n)
		visited[i]= v[i];
	visited[curr] = 1;	
	if(a[curr] == 1)
		meow++;
	if(curr == dest)
	{
		if(meow <= m)
			ans++;
	}
	for(int i=0;i<n;i++)
	{
		if(adj[curr][i] == 1 && visited[i] != 1)
		{
			visited[i] = 1;
			dfs(i,meow,dest,visited);
		}
	}

}	
int main()
{
	scan2(n, m);
	loop(i,n)
		scan1(a[i]);
	loop(i,n-1)
	{
		int u,v;
		scan2(u, v);
		adj[u-1][v-1] = 1;
		adj[v-1][u-1] = 1;
	}
	int count = 0, ct = 0;
	int res[100] ={0};
	loop(i,n)
	{
		ct = 0;
		loop(j,n)
		{
			if(adj[i][j] == 1)
				ct++;
		}
		if(ct == 1 && i!=0)
			res[count++] = i;
	}
	int vis[n];
	loop(i,n)
		vis[i] = 0;
	loop(i,count)
	{
		dfs(0,0,res[i],vis);
	}
	print1(ans);
	return 0;
}
		