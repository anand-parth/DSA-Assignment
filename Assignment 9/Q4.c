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
	int p[n], d[n];
	loop(i,n)
	{
		scan2(p[i],d[i]);
	}
	int petrol = 0;
	loop(i,n)
	{	
		int c = 0;
		petrol = p[i];
		for(int j=i;j<n+i;j++)
		{
			int val  = j % n;
			if(petrol < d[val])
			{
				// print1(i);
				break;
			}
			else
			{
				print1(petrol);
				petrol = petrol - d[val] + p[(val+1)%n];
				c++;
			}
		}
		if(c == n)
		{
			print1(i);
			break;
		}
	}	
	return 0;
}