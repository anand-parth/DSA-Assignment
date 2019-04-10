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
int cm = 9999;
int cache[100];
int minimum(int n)
{
	if(n == 1)
	{
		return 1;
	}
	else
	{
		// print2(n,c);
		int mini = 99999;
		for(int i=2;i*i<=n;i++)
		{
			if(n % i == 0)
			{
				mini = min(mini,minimum(n/i)); 
			}
		}
		mini = min(mini, minimum(n-1));
		return 1 + mini;
	}
	
}
int main()
{
	int q;
	scan1(q);
	loop(i,q)
	{
		int n;
		scan1(n);
		cm = 9999;
		cm = minimum(n);
		print1(cm);
	}
	return 0;
}