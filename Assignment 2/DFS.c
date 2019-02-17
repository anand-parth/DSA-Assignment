#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int visited[1000],graph[1000][1000];
int n;
int cnt=1;

void dfs(int i)
{
	printf("\n%d", i);
	visited[i] = 1;
	for(int j=0;j<n;j++)
	{
		if(visited[j]!=1 && graph[i][j]!=0)
		{
			dfs(j);
		}
		if(visited[j]==1 &&  j!=i)
			printf("CF");

	}
}
int main()
{
	int e;
	scanf("%d %d", &n, &e);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &graph[i][j]);
		}
	}
	for(int i=0;i<n;i++)
		visited[i] = 0;

	dfs(0);

	return 0;
}

