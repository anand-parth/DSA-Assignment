#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define loop(i,n) for(int i=0;i<n;i++)
int n,x,y;
int a[100][100];
int *gpath;
int len;
void dfs(int src, int dest, int *path, int *vis, int c)
{
	int *p = (int *)calloc(n,sizeof(int*));
	int *v = (int *)calloc(n,sizeof(int*));
	loop(i,c)
	{
		v[i] = vis[i];
		p[i] = path[i];
	}
	if(src == dest)
	{
		gpath = p;
		len = c;
		return;
	}
	for(int i=0;i<n;i++)
	{
		if(a[src][i]!=0 && v[i]!=1)
		{
			v[i] = 1;
			p[c] = i;
			dfs(i,dest,p,v,c+1);
		}
	}
}
int main()
{
	scanf("%d %d %d", &n ,&x, &y);
	x = x-1;
	y = y-1;
	loop(i,n)
	{
		loop(j,n)
		{
			a[i][j] = 0;
		}
	}
	loop(i,n-1)
	{
		int u,v;
		scanf("%d %d", &u ,&v);
		a[u-1][v-1] = 1;
		a[v-1][u-1] = 1;
	}
	int count = 0;
	loop(i,n)
	{
		loop(j,n)
		{
			if(j == i)
				continue;
			int *v=(int *)calloc(n,sizeof(int *));
			int *p=(int *)calloc(n,sizeof(int *));
			v[i]=1;
			p[0]=i;
			dfs(i,j,v,p,1);
			int flag=0;
			for(int k=0;k<len;k++)
			{
				if(gpath[k]==x && flag==0)
					flag++;
				else if(gpath[k]==y && flag==1)
					flag++;
			}
			if(flag!=2)
			{
				count++;
			}
		}
	}
	printf("%d ",count);

	return 0;
}