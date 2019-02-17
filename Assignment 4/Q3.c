#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)

int a[100];
int main()
{
	int len = 0;
	while(1)
	{
		int n;
		scanf("%d", &n);
		if(n == -1)
			break;
		a[len++] = n;	
	}
	// int ct = 0;
	// for(int i=0;i<len-1;i+=2)
	// {
	// 	if(a[i] != a[i+1])
	// 	{
	// 		printf("%d\n",a[i]);
	// 		ct = 1;
	// 		break;
	// 	}
	// }
	// if(ct != 1)
	// 	printf("%d\n",a[len-1]);
	int val = 0;
	loop(i,len)
	{
		val = val ^ a[i]; 
	}
	printf("%d ",val);

	return 0;
}