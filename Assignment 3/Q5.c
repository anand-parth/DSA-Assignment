	#include<stdio.h>
#include<stdlib.h>
int a[100][100];
int count = 0;
int v[100][100];

int canBeIndexed(int i, int j, int n)
{
	return (0<=i && i<= n-1 && 0<=j && j <= n-1);
}
void dfs(int r,int c,int n)
{
	count ++;
	v[r][c] = 1;
	for(int i=-1;i<=1;i++)
	{
		for(int j=-1;j<=1;j++)
		{
			int y = r + i;
			int z = c + j;
			if(canBeIndexed(y,z,n))
			{
				if(a[y][z] == 1 && v[y][z]!=1)
				{
					dfs(y,z,n);
					
				}	
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			v[i][j] = 0;
		}
	}

	int max = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			count = 0;
			if(a[i][j] == 1 && v[i][j]!=1)
			{
				dfs(i,j,n);
				if(count > max)
					max = count;
			}
		}
	}
	printf("%d\n",max);

	return 0;
}