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
int time = 0;
int vis[100];
int minimum(int a[], int n,int b[])
{
	int min = 9999;
	int minid = 0;
	int flag = 0;
	loop(i,n)
	{
		if(a[i] <= time)
		{	
			flag = 1;	
			if(b[i] < min && vis[i] == 0)
			{
				min = b[i];
				minid = i;
			}
		}
	}
	if(flag == 0)
	{
		int min = 9999;
		int minid = 0;
		loop(i,n)
		{
			if(a[i] < min)
			{
				min = a[i];
				minid = i;
			}
		}
		time = min;
		return minid;
	}
	vis[minid] = 1;
	return minid;
}	
int main()
{
	int n;
	scan1(n);
	int a[n], b[n];
	int ans = 0;
	loop(i,n)
	{
		scan2(a[i],b[i]);
	}
	loop(i,n)
	{
		print1(i);
		int val = minimum(a,n,b);
		if(a[val] <= time)
		{
			time = time + b[val];
			ans = ans + time - a[val];
		}
		print1(ans);
	}
	printf("%.1f ",(float) ans/n);
	return 0;
}
		