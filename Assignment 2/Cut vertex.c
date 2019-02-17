#include<string.h>
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int c[100][100];
int visited[100];
int cres[100][100];
int res[100][100];
void dfs(int i,int e)
{
	int ct = 0;
	visited[i] = 1;
	for(int j=1;j<=e;j++)
	{
		if(visited[j]<1 && cres[i][j]!=0)
		{
			c[i][j] = 1;
			c[j][i] = 1;
			dfs(j,e);
		}
	}
}
void initvis(int e)
{
	for(int i=1;i<=e;i++)
		visited[i] = 0;
}
int main()
{
	bool flag = false;
	int n,e;
	scanf("%d %d", &n, &e);
	
	for(int i=1;i<=e;i++)
	{
		for(int j=1;j<=e;j++)
		{
			res[i][j] = 0;
		}
	}
	for(int i=1;i<=e;i++)
	{
		int u,v;
		scanf("%d %d", &u, &v);
		res[u][v] = 1;
		res[v][u] = 1;
	}


			for(int i=1;i<=e;i++)
			{
				visited[i] = 1;
				int count = 0;
				dfs(i,e);
				for(int j=1;j<=e;j++)
				{
					if(visited[j]!=1)
					{
						dfs(j,e);
						count++;
					}
				}
				initvis(e);
				if(count>=2)
				{
					printf("No. of CC in Row Number %d is %d\n", i, count);
				for(int j=1;j<=e;j++)
				{
					if(visited[j]!=1)
					{
						for(int k=1;k<=e;k++)
						{
							for(int l=1;l<=e;l++)
							{
								printf("%d ", c[j][k]);
								c[k][l] = 0;
							}
							printf("\n");
							// printf("%d %d\n",i,row);
						}
						printf("\n*********\n");
					}
				}				
				}
				initvis(e);
		}

	
	return 0;
}