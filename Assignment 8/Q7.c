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


int main()
{
	int n;
	scan1(n);
	int a[n];
	loop(i,n)
		scan1(a[i]);
	int sum = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=i;j<n;j++)
		{
			int min = 9999;
			for(int k=i;k<=j;k++)
			{
				if(a[k] < min)
					min = a[k];
			}
			sum = sum + min;
		}
	}
	print1(sum);


	return 0;
}