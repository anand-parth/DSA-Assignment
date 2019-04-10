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
int arr[10000000];
int minimum(int n)
{
	if(arr[n] != -1)
		return arr[n];
	else if(n == 0)
	{
		arr[n] = 0;
		return arr[n];
	}
	else
	{
		arr[n] = minimum(n-1) + 1;
		for(int i=2;i*i<=n;i++)
		{
			if(n % i == 0)
			{
				arr[n] = min(minimum(n/i)+1,arr[n]);
			}
		}
		return arr[n];
	}
	
}
int main()
{
	int q;
	scan1(q);
	loop(i,10000000)
		arr[i] = -1;
	loop(i,q)
	{
		int n;
		scan1(n);
		print1(minimum(n));
	}
	return 0;
}