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
int n;
int inLimits(int i, int j)
{
	if(i>=0 && j>=0 && i<n && j<n)
		return 1;
	else
		return 0;
}
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
		
int main()
{
	int m;
	scan2(n,m);
	char **a = (char **)malloc(n*sizeof(char *));
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
	int flag = 0;
	for(int row=0;row<t;row++)
	{
	int ct = 1;	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(a[i][j] == b[row][0])
				{
					flag = 0;
					int val1 = i;
					int val2 = j;
					for(int l=1;l<strlen(b[row]);l++)
					{
						if(inLimits(i+1,j) && a[i+1][j] == b[row][l])
						{
							printf("%d i ",i);
							i = i+1;
							ct++;
						}
						else if(inLimits(i-1,j) && a[i-1][j] == b[row][l])
						{
							printf("%d i ",i);
							i = i-1;
							ct++;
						}
						else if(inLimits(i,j+1) && a[i][j+1] == b[row][l])
						{
							printf("%d j ",j);
							j = j+1;
							ct++;
						}
						else if(inLimits(i,j-1) && a[i][j-1] == b[row][l])
						{
							printf("%d j ",j);
							j = j-1;
							ct++;
						}
						else
						{
							flag = 1;
							ct = 1;
							i = val1;
							j = val2;
							break;
						}
					}
				}
			// if(ct == strlen(b[row]))
			// 	printf("YES\n");
			// else
			// 	printf("NO\n");			

		}
	}
	if(flag != 1)
		printf("%d A %d ",ct,row);

	}
	return 0;
}
		