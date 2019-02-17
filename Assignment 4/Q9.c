#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
int m;
int arr[100];
int binarySearch(int l, int r, int x)
{
	if(r >= l)
	{
		m = l + (r-l)/2;
		printf("%d ",m);
		if(arr[m] == x)
			return m;
		else if(arr[m] < x)
			return binarySearch(m+1, r, x);
		else
			return binarySearch(l, m-1, x);

	}
	return -1;

}
int main()
{
	int n;
	scanf("%d",&n);
	loop(i,n)
		scanf("%d",&arr[i]);
	int k;
	scanf("%d",&k);
	int val = binarySearch(0,n-1,k);
	if(val != -1)
	{
		printf("Naruto %d\n", val+1);
	}
	else
	{
		if(k < arr[m])
			printf("Sasuke %d\n", m+1);
		else
			printf("Sasuke %d\n", m+2);
	}
	
	return 0;
}