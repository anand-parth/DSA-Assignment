#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
void bubbleSort(int a[], int n)
{
	int ct = 0;
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
int checkcount(int a[], int l, int r, int c)
{
	if(2*a[l] - a[r] >= 0)
	{
		int ct = 0;
		for(int i=l+1; ;i++)
		{
			if(a[i] == a[l])
				ct++;
			else
				break;
		}
		c = c + ct;
		ct = 0;
		for(int i=r-1; ;i--)
		{
			if(a[i] == a[r])
				ct++;
			else
				break;
		}
		c = c + ct;
		return c;
	}
	else
	{
		checkcount(a,l+1,r,c+1);
		checkcount(a,l,r-1,c+1);
	}
}
int main()
{	
	int n;
	scanf("%d", &n);
	int a[n];
	loop(i,n)
		scanf("%d", &a[i]);
	bubbleSort(a, n);
	printf("%d\n", checkcount(a,0,n-1,0));

	return 0;
}