#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
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
	scanf("%d %d",&n,&m);
	int a[n], b[m];
	loop(i,n)
		scanf("%d",&a[i]);
	loop(i,m)
		scanf("%d",&b[i]);
	int res[m+n];
	int ct = 0;
	for(int i=0;i<m;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(a[j] == b[i])
			{
				res[ct++] = a[j];
				a[j] = -1;
			}
		}
	}
	int res2[m+n-ct];
	int ct2 = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] != -1)
			res2[ct2++] = a[i];
	}
	bubbleSort(res2, ct2);
	for(int i=ct;i<m+n;i++)
	{
		res[i] = res2[i-ct];
	}
	int len = ct + ct2;
	loop(i,len)
		printf("%d ",res[i]);
	printf("\n");
	return 0;
}