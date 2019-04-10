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
int main()
{
	int n;
	scan1(n);
	int b[n];
	loop(i,n)
		scan1(b[i]);
	loop(i,n)
	{
		a[i][i*2+1] = 1;
		a[i*2+1][i] = 1;
		a[i][i*2+2] = 1;
		a[i*2+2][i] = 1;
	}
	// loop(i,n)
	// {
	// 	loop(j,n)
	// 	{
	// 		printf("%d ",a[i][j]);
	// 	}
	// 	pn();
	// }
	loop(i,n)
	{
		for(int j=i+1;j<n;j++)
		{
			if(a[i][j] == 1)
				print2(b[i],b[j]);
		}
	}
	loop(i,n)
	{
		loop(j,n)
		{
			if(a[j] < a[j*2 + 1])
			{
				c+=2;
			}
		}
	}
	return 0;
}