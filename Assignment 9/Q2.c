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
// #define loop(i,a,n) for(int i=a;i<n;i++)

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b

int main()
{
	int n,m,x;
	scan3(n,m,x);
	int a[n], b[m];
	loop(i,n)
		scan1(a[i]);
	loop(i,m)
		scan1(b[i]);
	int count = 0, i = 0,j = 0;
	int sum = 0;
	while(i<n && sum+a[i]<=x)
	{
		sum = sum + a[i];
		i++;
	}
	count = i;
	while(j < m && i >= 0)
	{
		sum = sum + b[j];
		j++;
		while(sum > x && i>0)
		{
			i--;
			sum = sum - a[i];
		}
		if(sum <=x && i+j > count)
			count = i+j;
	}
	print1(count);
	return 0;
}