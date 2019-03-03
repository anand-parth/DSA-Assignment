#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

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
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
int power(int x, int y)
{
	int res = 1;
	for(int i=1;i<=y;i++)
	{
		res = res*x;
	}
	return res;
}
void bubbleSort(int a[], int n)
{
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			int t1 = a[j];
			int t2 = a[j+1];
			int c1=0, c2=0;
			while(t1 > 0)
			{
				t1/=10;
				c1++;
			}
			while(t2>0)
			{
				t2/=10;
				c2++;
			}
			int val1 = a[j]*power(10,c2) + a[j+1];
			int val2 = a[j+1]*power(10,c1) + a[j];
			if(val1 < val2)
				swap(&a[j], &a[j+1]);.

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
	bubbleSort(a,n);
	loop(i,n)
		printf("%d",a[i]);
	printf("\n");

	return 0;
}
		