#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t; 
}
int binarySearch(int arr[], int l, int r, int x)
//binarySearch(arr,0,n-1,valToBeSearched)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        // printf("%d ",mid);
 		if (arr[mid] == x)  
            return mid;
 
      	if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 		
 		return binarySearch(arr, mid+1, r, x);
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
			}
		}
	}
	return a;
}
int main()
{
	int n;
	scanf("%d", &n);
	int a[n];
	loop(i,n)
		scanf("%d",&a[i]);
	int d;
	scanf("%d",&d);

	int flag = 0;
	int *c;
	c = sortA(a,n);
	for(int i=0;i<n;i++)
	{
		int m = binarySearch(c,0,n-1,d+a[i]);
		if(m != -1)
		{
			flag = 1;
			printf("%d ",c[i]+c[m]);
		}
	}		
	if(!flag)
		printf("-1\n");

	return 0;
}

// Binary search with parameter as d-(array no.)