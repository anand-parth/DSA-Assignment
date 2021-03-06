#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)

#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)
// #define loop(i,a,n) for(int i=a;i<n;i++)

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int n,m;
int ans;
char **a;
int canBeIndexed(int i, int j)
{
	return (0<=i && i<= n-1 && 0<=j && j <= m-1);
}
void dfs(int r,int c,char s[],int id,int len)
{
	if(id > len - 1 || a[r][c] != s[id])
		return;
	if(id == len - 1)
	{
		ans = 1;
		return;	
	}	

	if(canBeIndexed(r+1,c))
	{
		dfs(r+1,c,s,id+1,len);			
	}		
	if(canBeIndexed(r-1,c))
	{
		dfs(r-1,c,s,id+1,len);			
	}
	if(canBeIndexed(r,c+1))
	{
		dfs(r,c+1,s,id+1,len);			
	}
	if(canBeIndexed(r,c-1))
	{
		dfs(r,c-1,s,id+1,len);			
	}			
}
int main()
{
	scan2(n,m);
	a= (char **)malloc(n*sizeof(char *));
	loop(i,n)
	{
		a[i] = (char*)malloc(m*sizeof(char));
		scanf("%s",a[i]);
	}
	int t;
	scan1(t);
	char **b;
	b = (char**)  malloc(t*sizeof(char*));
	loop(i,t)
	{
		b[i] = (char*) malloc(100*sizeof(char));
		scanf("%s",b[i]);
	}
	for(int row =0;row<t;row++)
	{
		int flag = 0;
		ans = 0;

		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(a[i][j] == b[row][0])
				{
					dfs(i,j,b[row],0,strlen(b[row]));
					if(ans)
						break;
				}
			}
			if(ans)
				break;
		}
		if(ans != 1)
				printf("NO\n");
		else
			printf("YES\n");

	}
		return 0;
}

