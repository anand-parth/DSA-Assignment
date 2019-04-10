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
	int n;
	scan1(n);
	int a[n], e[n], ec[n];
	loop(i,n)
	{
		scan2(a[i], e[i]);
		ec[i] = e[i];
	}
	int wt[n];
	loop(i,n)
		wt[i] = 0;
	int t;
	scan1(t);
	int time = 0;
	while(1)
	{
		print1(10);
		int done = 1;
		loop(i,n)
		{
			if(ec[i] > 0)
			{
				done = 0;
				if(ec[i] > t)
				{
					time += t;
					ec[i] -= t; 
				}
				else
				{
					time += ec[i];
					wt[i] = time - e[i];
				}
			}
		}
		if(done == 1)
			break;
	}
	loop(i,n)
		print1(wt[i]);

	return 0;
}
		