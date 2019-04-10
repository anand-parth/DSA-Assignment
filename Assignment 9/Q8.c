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
	int k,w,n;
	scan3(k,w,n);
	int p[n];
	int c[n];
	loop(i,n)
		scan1(p[i]);
	loop(i,n)
		scan1(c[i]);
	int max = 0, ct = 0;
	int val;
	loop(j,n)
	{
		max = 0;
		loop(i,n)
		{
			if(c[i] <= w)
			{
				if((p[i]) >= max)
				{
					max = p[i];
					val = i;
				}
			}
		}
		w = w + max;
		ct++;
		p[val] = -1, c[val] = -1;
		if(ct == k)
			break;
	}
	print1(w);
	return 0;
}