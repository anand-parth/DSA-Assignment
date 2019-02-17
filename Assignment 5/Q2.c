#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	int a[n], b[m];
	loop(i,n)
		scanf("%d",&a[i]);
	loop(i,m)
		scanf("%d",&b[i]);
	int c[m+n];
	
	loop(i,m+n)	
		printf("%d",c[i]);

	return 0;
}