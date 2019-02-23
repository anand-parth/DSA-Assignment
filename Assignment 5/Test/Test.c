#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)

int fact(int n)
{
	if(n == 0)
		return 1;
	else
		return n*  fact(n-1);
}
int mian()
{
	printf("%d\n",fact(5));
}