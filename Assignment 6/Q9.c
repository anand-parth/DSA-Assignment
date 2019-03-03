#include<stdio.h>
#include<stdlib.h>
#include<limits.h>
#define max(a,b) (a>b)?a:b
int a[76];
void count(int n)
{
	for(int i=1;i<=6;i++)
		a[i] = i;
	for(int i=7;i<=n;i++)
	{
		int val = max(3*a[i-4],4*a[i-5]);
		a[i] = max(2*a[i-3], val);
	}
}	
int main()
{
	int n;
	scanf("%d", &n);
	count(n);
	printf("%d\n",a[n]);
	return 0;
}
		