#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
int binarySearch(int arr[], int l, int r, int x)
//binarySearch(arr,0,n-1,valToBeSearched)
{
	if(r >= l)
	{
		int m = l+ (r-l)/2;
		if(arr[m] == x)
			return m;
		else if(arr[m]<x)
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
		scanf("%d",&a[i]);
	int k;
	scanf("%d",&k);
	int t;
	loop(i,n-1)
	{
		if(a[i] <= a[i+1])
			continue;
		else
		{
			t=a[i];
			a[i] = a[i+1];
			a[i+1] = t;
			t = i;
			break;
		}
	}
	// printf("%d\n",t);
	// loop(i,n)
	// 	printf("%d ",a[i]);
	if(k == a[t+1])
	{
		printf("%d\n",t+1);
	}
	else if(k == a[t])
	{
		printf("%d\n", t+2);
	}
	else
		printf("%d ", binarySearch(a,0,n-1,k)+1);
	

	return 0; 
}