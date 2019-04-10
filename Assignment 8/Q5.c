#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)
#define pn() printf("\n");
#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)
#define min(a,b) (a<b)?a:b		
int a[100];

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
int power(int x, int y)
{
	int res = 1;
	for(int i=1;i<=y;i++)
		res = res*x;
	return res;
}
int main()
{
	int n;
	scan1(n);
	loop(i,n)
		scan1(a[i]);
	bubbleSort(a,n);
	loop(i,n)
		printf("%d ", a[i]);
	pn();
	loop(i,n)
	{
		if(a[i] == 0)
			continue;
		if(a[i] != 0)
		{
			swap(&a[i],&a[0]);
			swap(&a[i+1],&a[1]);
			break;
		}
	}
	loop(i,n)
		print1(a[i]);
	int n1=0, n2=0;
	int c=0;
	for(int i=0;i<n-1;i+=2)
	{
		n1 = n1*10 + a[i];
		n2 = n2*10 + a[i+1];
		c++;
	}
	if(n%2 == 1)
		n1 = n1*10 + a[n-1];
	print1(n1+n2);

	return 0;
}