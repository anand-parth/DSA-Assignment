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
	int n,k;
	scan2(n,k);
	int a[k];
	loop(i,k)
		scan1(a[i]);
	loop(i,k-1)
	{
		if(a[i] != a[i+1])
			break;
		if(i == k-2)
		{
			loop(j,n)
				printf("%d",a[0]);
			pn();
			return 0;
		}
	}

	return 0;
}

// 0 0 0 8
// 0 0 1 1
// 0 1 0 6
// 0 1 1 2
// 1 0 0 7
// 1 0 1 5
// 1 1 0 4
// 1 1 1 3

// 0 0 4
// 0 1 1
// 1 0 3
// 1 1 2