#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define loop(i,n) for(int i=1;i<=n;i++)
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
	int t;
	scanf("%d",&t);
	int ct = 0;
	int res[100];
	loop(i,t)
	{
		int y,z;
		scanf("%d %d",&y,&z);
		for(int i=1;i<=n;i++)
			visited[i] = 0;
		dfs(y,n);
		if(visited[z] == 1)
			res[ct] = 1;
		else
			res[ct] = 0;
		ct++;
	}
	for(int i=0;i<ct;i++)
		if(res[i] == 1)
			printf("YES\n");
		else
			printf("NO\n");
	return 0;
}