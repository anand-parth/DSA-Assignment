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
int res[100][100];	
int n;
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
void casezero()
{

}
int main()
{
	int n,m,k;
	scan3(n,m,k);
	loop(i,n)
	{
		loop(j,m)
			scan1(res[i][j]);
	}
	for(nt k=0;k<n;k++)
	{
		int tmp;
		int flag = 0;
		for(int i=0;i<m-1;i++)
		{
			int ti,tj;
			for(int j=i+1;j<m;j++)
			{
				if(res[k][j] < res[k][tmp])
				{
					ti = i;
					tj = j;	
				}
				loop(l,n)
				{
					swap(&res[l][tmp], &res[l][i]);
				}
			loop(i,n)
			{
				loop(j,m)
					printf("%d ",res[i][j]);
				printf("\n");
			}
			pn();
		}
		}
	}

	return 0;
}