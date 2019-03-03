#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d %d", &b, &c)
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
	int n;
	scan1(n);
	int a[n];
	loop(i,n)
		scan1(a[i]);
	int r[n][n];
	loop(i,n)
	{
		loop(j,n)
		{
			scan1(r[i][j]);
		}
	}
	int c[n];
	loop(i,n)
		c[i] = a[i];
	bubbleSort(c,n);
	int ct = 0;
	for(int t=0;t<n;t++)
	{
		for(int i=0;i<n;i++)
		{
			for(int j=i+1;j<n;j++)
			{
				// print1(j);
				ct = 1;
				if(a[j] < a[i] && j!=i && r[i][j] == 1)
					swap(&a[j],&a[i]);
			}
		}
	}
	loop(i,n)
	{
		printf("%d ",a[i]);
	}
	return 0;
}
		


// 7
// 5 2 4 3 6 7 1
// 0 1 1 1 1 1 1  
// 1 0 1 1 1 1 1  
// 1 1 0 1 1 1 1  
// 1 1 1 0 1 1 1  
// 1 1 1 1 0 1 1  
// 1 1 1 1 1 0 1  
// 1 1 1 1 1 1 0  
