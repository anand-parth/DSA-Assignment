#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	loop(i,n)
		scanf("%d",&a[i]);
	int val = 0;
	loop(i,n)
	{
		val = val ^ a[i]; 
	}
	printf("%d ",val);

}