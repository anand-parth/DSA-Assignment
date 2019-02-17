#include<stdio.h>
#include<stdlib.h>
int graph[20][20];
int visited[20];
int q[20];
int n,f=0,r=-1;

void bfs(int v)
{
	for(int i=0;i<n;i++)
	{
		if(visited[i]!=1 && graph[v][i]!=0)
			q[++r] = i;
		if(f<=r)
		{
			visited[q[f]] = 1;
			bfs(q[f++]);
		}
	}
}
int main()
{
	scanf("%d", &n);
	for(int i=0;i<n;i++)
	{
		q[i] = 0;
		visited[i] = 0;
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	bfs(0);
	for(int i=0;i<n;i++)
	{
		if(visited[i])
			printf("%d\n", i);
	}
	return 0;
}
