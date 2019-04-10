#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)
#define pn() printf("\n");

#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)
// #define loop(i,a,n) for(int i=a;i<n;i++)

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int a[100][100];
int n;
int c =0;
void PrintMatrix(int i, int j, int k, int p)
{
	int ct = 0;
	for(int r=k;r<k+i;r++)
	{
		for(int c=p;c<p+j;c++)
		{
			// printf("%d ",a[r][c]);
			if(a[r][c] == 1)
				ct++;
		}
	}
	if(ct == 1)
	{
		print2(i,j);
		c = c + ct;
	}
}
int main()
{
	scan1(n);
	loop(i,n)
	{
		loop(j,n)
		{
			scan1(a[i][j]);
		}
	}
	for (int i = 1; i <=n; ++i)
	{
	    for (int j = 1; j <=n; ++j)
	    {
	     for (int k = 0; k <= (n - i); ++k)
	      {
	        for (int p = 0; p <= (n - j); ++p)
	        {
	           PrintMatrix(i, j, k, p);
	        }
	      }
	    }
	  }
	  print1(c);
	return 0;
}