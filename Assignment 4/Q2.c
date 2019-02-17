#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
int power(int k, int j)
{
	int res = 1;
	for(int i=1;i<=j;i++)
	{
		res = res*k;
	}
	return res;
}
int main()
{
	int n,k;
	scanf("%d %d", &n, &k);
	int val = 0, pow = 0, ct = 0;
	for(int i=k;i<=n;i++)
	{
		pow = 0, val = 0;
		for(int j=0; ;j++)
		{
			pow = i/(power(k,j));
			if(pow == 0)
				break;
			else
			{	
				val += pow;
				if(val == n)
				{
					ct = 1;
					break;
				}
			}
		}
		if(ct == 1)
		{
			printf("%d\n",i);
			break;
		}
	}


	return 0;

}

// Take a loop to find all such v's, works for v~10k.