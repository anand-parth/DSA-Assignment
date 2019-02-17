#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define loop(i,n) for(int i=1;i<n;i++)
int visited[1000];
int a[1000][1000];
void dfs(int i, int n)
{
	visited[i] = 1;
	for(int j=1;j<=n;j++)
	{
		if(visited[j]<1 && a[i][j]!=0)
		{
			dfs(j, n);
		}
	}
}
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	for(int i=1;i<=m;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
	}
	for(int row=1;row<=n;row++)
	{
		int ct = 0;
		for(int i=1;i<=n;i++)
			visited[i] = 0;
		dfs(row,n);
		for(int i=1;i<=n;i++)
			if(visited[i] == 1)
				ct++;
		if(ct == n)
			printf("%d ",row);
	}
	return 0;
}