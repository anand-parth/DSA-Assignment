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
	int n;
	scan1(n);
	int ip[n];
	loop(i,n)
		scan1(ip[i]);
	int a[n],y[n],z[n];
	loop(i,n)
	{
		a[i] = ip[i]%10;
	}
	loop(i,n)
	{
		for(int i=0;i<10;i++)
	  	{
	    	if(c[i]>0)
	    {
	      c[i] = c[i] + sum;
	      sum = c[i];
	    }
	  }
	  int b[10] ={0};
	  for(int i=n-1;i>=0;i--)
	  {
	    b[c[a[i]]] = a[i];
	    c[a[i]]--;
	  }
	}
	
	return 0;
}
		