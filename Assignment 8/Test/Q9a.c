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
int gmin = 9999;
void check(int i, int a[], int c, int n)
{
	int arr[n];
	loop(i,n)
		arr[i] = a[i];
	if(i == n-1)
	{
		loop(i,n)
			printf("%d ",arr[i]);
		print1(c);
		if(c < gmin && c > 0)
			gmin = c;
		return ;
	}
	else
	{
		int d = arr[i] - arr[i+1];
		if(d == 0)
			check(i+1,arr,c,n);
		else if(d > 0)
		{
			arr[i+1] += d;
			check(i+1,arr,c+d,n);
		}
		else if(d < 0)
		{
			arr[i] -= d;
			check(i+1,arr,c+d,n);	
		}
	}
}
int main()
{
	int n;
	scan1(n);
	int a[n];
	loop(i,n)
		scan1(a[i]);
	check(0,a,0,n);
	print1(gmin);
	return 0;
}