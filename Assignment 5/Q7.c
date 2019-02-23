#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int d[100];
int min(int a, int b)
{
	return (a < b) ? a : b;
}
int max(int a, int b)
{
	return (a < b) ? b : a;
}
int main()
{
	int n;
	scanf("%d", &n);
	loop(i,n)
	scanf("%d", &d[i]);
	int src = 0;
	loop(i,n)
	{
		if(d[i] == 0)
			src = i;
	}
	int a[100];
	int ct = 0;
	loop(i,n)
	{
		if(d[i] == 1)
			a[ct++] = i;
	}


	return 0;
}