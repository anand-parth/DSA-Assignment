#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)

#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)
// #define loop(i,a,n) for(int i=a;i<n;i++)

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
		
int main()
{
	int n;`
	scan1(n);
	if(n <= 10)
	{
		loop(i,n)
			printf("%d ",i);
	}
	else
	{
		int flag = 0;
		loop(i,11)
			printf("%d ",i);
		for(int i=11;i<n;i++)
		{
			flag = 0;
			int t = i;
			int d = t%10;
			t/=10;
			while(t > 0)
			{
				int d2 = t%10;
				t/=10;
				if(abs(d2-d) == 1)
				{
					d = d2;
					continue;
				}
				else
				{
					flag = 1;
					break;
				}

			}
			if(flag != 1)
				printf("%d ",i);
		}
	}
	return 0;
}
		