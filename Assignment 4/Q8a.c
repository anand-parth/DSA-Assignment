#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
// void swap(int *x, int *y)
// {
// 	int t = *x;
// 	*x = *y;
// 	*y = t; 
// }
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
	return -2;
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
	
	// int b[n];
	// loop(i,n)
	// 	b[i] = i+1;
	// for(int i=0;i<n-1;i++)
	// {
	// 	// printf("%d ",a[i]);
	// 	if(a[i]>a[i+1])
	// 	{
	// 		swap(&a[i],&a[i+1]);
	// 		swap(&b[i],&b[i+1]);
	// 	}
	// }
	
	printf("%d\n",binarySearch(a,0,n-1,k)+1);
	return 0;
}