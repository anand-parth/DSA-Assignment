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
int power(int b, int e)
{
	int res = 1;
	for(int i=1;i<=e;i++)
	{
		res = res*b;
	}
	return res;
}
int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	loop(i,n)
		scanf("%d",&a[i]);
	bubbleSort(a,n);
	int s =0;
	loop(i,n)
		s = s + a[i];
	int b0[n], b1[n], b2[n];
	int c0 = 0,c1 = 0,c2 = 0;
	loop(i,n)
	{
		if(a[i]%3 == 0)
			b0[c0++] = a[i];
		else if(a[i]%3 == 1)
			b1[c1++] = a[i];
		else
			b2[c2++] = a[i];
	}
	int val = s % 3;
	int removed1 = -1;
	int removed2 = -1;
	if(val == 0)
	{
		;
	}
	else if(val == 1)
	{
		if(c1 != 0)
			removed1 = b1[0];
		else
		{
			if(c2 >=2)	
				removed1 = b2[0];
				removed2 = b2[1];
		}		 
	}
	else
	{
		if(c2 != 0)
			removed1 = b2[0];
		else
		{
			if(c1 >=2)	
				removed1 = b1[0];
				removed2 = b1[1];
		}		 
	}
	int res[100];
	int ct = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i] == removed1 || a[i] == removed2)
			;
		else
			res[ct++] = a[i];
	}
	int sum = 0, flag = 0;
	for(int i=0;i<ct;i++)
	{
		flag = 1;
		sum = sum + res[i]*power(10,ct-1-i);
	}
	if(flag)
		printf("%d\n",sum);
	else
		printf("No such number\n");

	return 0;
}