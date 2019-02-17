#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int a[100][100];
int cycle[100];
int q[100];
int min = 100000;
void dfs(int src,int curr,int n,int path[],int visited[],int c,int dist)
{
	int p[n+1];
	int vis[n+1];
	for(int i=0;i<c;i++)
	{
		p[i] = path[i];
		vis[i] = visited[i];
	}
	for(int i=0;i<n;i++)
	{
		if(a[curr][i]>0 && visited[i]!=1)
		{
			printf("%d %d ", curr, i);
			p[c] = i;
			visited[i] = 1;
			if(i==src && c!=1)
			{
				// if(dist<=min)
				// {
					min = dist+1;
					printf("%d\n", min);
				// }
			}
			else
				dfs(src,i,n,p,vis,c+1,(dist+a[curr][i]));
		}
	}
}
int main()
{
	int n,e;
	scanf("%d %d", &n,&e);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = 0;
		}
	}
	for(int i=0;i<e;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		a[u][v] = 1;
	}
	int path[n+1];
	int visited[n+1];
	for(int i=0;i<n;i++)
	{
		path[0] = i;
		dfs(i,i,n,path,visited,1,0);
	}
	printf("%d\n",min);
	return 0;
}