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
int a[100][100];
int p[100];
int n;
int main()
{
	scan1(n);
	loop(i,n)
		scan1(p[i]);
	int ct = 0;
	loop(i,n)
	{
		if(p[i] == i+1)
			ct++;
	}
	if(ct == 1)
	{
		print1(0);
		loop(i,n)
			printf("%d ",p[i]);
		return 0;
	}
	loop(i,n)
	{
		if(p[i] != i+1)
		{
			a[i][p[i]-1] = 1;
			a[p[i]-1][i] = 1;
		}
	}	
	loop(i,n)
	{
		loop(j,n)
		{
			printf("%d ",a[i][j]);
		}
		pn();
	}

	return 0;
}