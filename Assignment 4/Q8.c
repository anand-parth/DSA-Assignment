#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
int b[100];
void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t; 
}
int binarySearch(int arr[], int l, int r, int x)
{
	if(r >= l)
	{
		int m =l + (r-l)/2;
		if(arr[m] == x)
			return m;
		else if(arr[m] < x)
			return binarySearch(arr, m+1, r, x);
		else
			return binarySearch(arr, l, m-1, x);

	}
	return -1;
}
int* sortA(int a[],int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j],&a[j+1]);
				swap(&b[j],&b[j+1]);
			}
		}
	}
	return a;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	loop(i,n)
		scanf("%d", &a[i]);
	int k;
	scanf("%d",&k);
	loop(i,n)
		b[i] = i+1;
	int *c;
	c = sortA(a,n);
	printf("%d\n",b[binarySearch(c,0,n-1,k)]);
	return 0;
}