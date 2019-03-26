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
int a[100];
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
void print(int n)
{
	loop(i,n)
		printf("%d ",a[i]);
	pn();
}	
int main()
{
	int n,k;
	scan2(n,k);
	loop(i,n)
	{
		scan1(a[i]);
	}
	bubbleSort(a,n);
	int ct = 0;
	loop(i,n)
	{	
		if(a[0] < k)
		{
			ct ++;
			a[0] = a[0] + 2*a[1];
			a[1] = 9999;
		}
		
		bubbleSort(a,n);
		if(a[0] >= k)
			break;
	}
	print1(ct);
	return 0;
}
