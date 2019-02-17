#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int n,x,y;
int a[100][100];
int ct = 0;
void dfs(int vis[n],int s,int dest,int src,int path[n],int c)
{
	int *p=(int*)calloc(n,sizeof(int));
	int *v=(int*)calloc(n,sizeof(int));
	for(int i=0;i<n+1;i++)
	{
		p[i]=path[i];
		v[i]=vis[i];
	}
	if(p[c-1]==dest && c!=1) 
	{
		for(int i=0;i<c;i++)
		{
			if(p[i] == x-1)
			{
				for(int j=i+1;j<c;j++)
				{
					if(p[j] == y-1)
					{
						ct--;
						// printf("A");
						break;
					}
				}
			}
		}
		ct++;
	return ;
	}
	for(int i=0;i<n;i++)
	{
		if(a[src][i]>0 && !v[i])
		{
			vis[i] = 1;
			p[c]=i;
			dfs(v,s,dest,i,p,c+1);
		}
	}
}
int main()
{
	scanf("%d %d %d",&n,&x,&y);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			a[i][j] = 0;
		}
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d %d",&u,&v);
		a[u-1][v-1] = 1;
		a[v-1][u-1] = 1;
	}
	int *path;
	int *vis;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(i == j) 
				continue;
			path = calloc(n,sizeof(int));
			vis = calloc(n,sizeof(int));
			path[0] = i;
			vis[i] = 1;
			dfs(vis,i,j,i,path,1);
		}
	}

	printf("%d\n",ct);
	return 0;
}