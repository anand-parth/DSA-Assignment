#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int n,min=9999;
int len;
int dfscall;
void dfs(int g[n][n],int vis[n],int s,int src,int path[100],int c,int dist);
int* cycle1;

void dfs(int g[n][n],int vis[n+1],int s,int src,int path[n+1],int c,int dist)
{
	int *p=(int*)calloc(n+1,sizeof(int*));
	int *v=(int*)calloc(n+1,sizeof(int*));
	if(src!=s)
		vis[src]=1;
	for(int i=0;i<n+1;i++)
	{
		p[i]=path[i];
		v[i]=vis[i];
	}

	if(p[c-1]==s && c!=1) 
	{
		if(dist<=min)
		{
			min=dist;
			cycle1=p;
			len=c;
			if(dfscall!=1)
			{
				for(int j=0;j<len;j++)
					printf("%d ",cycle1[j]);
				printf("\n");
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		if(g[src][i]>0 && !v[i])
		{
			p[c]=i;
			dfs(g,v,s,i,p,c+1,dist+g[src][i]);
		}
	}
}
void main()
{
	int e;
	scanf("%d %d",&n,&e);
	int g[n][n];
	int *a,*b,*p;
	cycle1=(int*)calloc(n+1,sizeof(int*));
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			g[i][j] = 0;
		}	
	}
	for(int i=0;i<e;i++)
	{
		int u,v,w;
		scanf("%d %d %d", &u, &v, &w);
		g[u][v] = w;
	}
	for(int i=0;i<n;i++)
	{
		dfscall = 1;
		a=(int*)calloc(n+1,sizeof(int*));
		b=(int*)calloc(n+1,sizeof(int));
		b[0]=i;
		dfs(g,a,i,i,b,1,0);
		
	}
	printf("%d\n",min);
	for(int i=0;i<n;i++)
	{
		dfscall = 2;
		a=(int*)calloc(n+1,sizeof(int*));
		b=(int*)calloc(n+1,sizeof(int));
		b[0]=i;
		dfs(g,a,i,i,b,1,0);
		// for(int j=0;j<len;j++)
		// 	printf("%d ",res[i][j]);
		// printf("\n");
		for(int j=0;j<n;j++)
		{
			g[j][i] = 0;
		}
	}
	
}