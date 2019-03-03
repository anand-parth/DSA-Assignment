#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int n;
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
void bubbleSort(int a[], int n, int b[])
{
	int ct = 0;
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				swap(&b[j], &b[j+1]);
			}
		}
	}
}
void bubbleSort1(int a[], int n, int b[])
{
	int ct = 0;
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j]<a[j+1])
			{
				swap(&a[j], &a[j+1]);
				swap(&b[j], &b[j+1]);
			}
		}
	}
}
int main()

{
	scanf("%d",&n);
	int a[n];
	loop(i,n)
		scanf("%d",&a[i]);
	int b[n];
	loop(i,n)
		b[i] = i;
	bubbleSort(a, n, b);
	int vis[n];
	loop(i,n)
		vis[i] = 0;
	int ct = 0;
	loop(i,n)
	{
		if(vis[i] == 1)
			continue;
		vis[i] = 1;
		int j = b[i];
		while(j != i)
		{
			vis[j] = 1;
			j = b[j];
		}
		ct++;
	}
	int val1, val2;
	val1 = n - ct;
	bubbleSort1(a, n, b);
	loop(i,n)
	vis[i] = 0;
	ct = 0;
	loop(i,n)
	{
		if(vis[i] == 1)
			continue;
		vis[i] = 1;
		int j = b[i];
		while(j != i)
		{
			vis[j] = 1;
			j = b[j];
		}
		ct++;
	}
	val2 = n - ct;
	printf("%d\n", val1 < val2 ? val1 : val2);
	return 0;
}