#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int arr[100];
void swap(int *x, int *y)
{
	int t = *x;
	*x = *y;
	*y = t; 
}
int check(int k, int n)
{
	int sum = 0;
	int res[n];
	loop(i,n)
		res[i] = arr[i] + (i+1)*k;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(res[j]>res[j+1])
			{
				swap(&res[j],&res[j+1]);
			}
		}
	}
	loop(i,k)
		sum = sum +res[i];
	return sum;
}
int main()
{
	int n,s;
	scanf("%d %d",&n,&s);
	loop(i,n)
		scanf("%d", &arr[i]);
	for(int i=1;i<=n;i++)
	{
		int val = check(i, n);
		// printf("%d ",val); 
		if(val < s)
			continue;
		else if(val == s)
			printf("%d %d \n", i,val);
		else
		{
			printf("%d %d \n", i-1, check(i-1,n));
			break;
		}
	}
}