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
#define min(a,b) (a<b)?a:b		

void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
void bubbleSort(int a[], int n)
{
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				
			}
		}
	}
}
int main()
{
	int n,m;
	scan2(n,m);
	int a[n];
	int s = 0;
	loop(i,n)
		scan1(a[i]);
	bubbleSort(a,n);
	int sum = 0, top = 0;
	loop(i,n-1)
	{
		if(a[i] > top)
			top++;
		sum = sum + a[i]-1;
		
	}
	int val = min(top,a[n-1]-1);
	sum = sum + val;
	print1(sum);

	return 0;
}