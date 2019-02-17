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
	int s =0;
	loop(i,n)
		s = s + a[i];
	int b0[n], b1[n], b2[n];
	int c0 = 0,c1 = 0,c2 = 0;
	loop(i,n)
	{
		if(a[i]%3 == 0)
			b0[c0++] = a[i];
		else if(a[i]%3 == 1)
			b1[c1++] = a[i];
		else
			b2[c2++] = a[i];
	}
	int val = s % 3;
	int removed1 = -1;
	int removed2 = -1;
	if(val == 0)
	{
		;
	}
	else if(val == 1)
	{
		if(c1 != 0)
			removed1 = b1[0];
		else
		{
			if(c2 >=2)	
				removed1 = b2[0];
				removed2 = b2[1];
		}		 
	}
	else
	{
		if(c2 != 0)
			removed1 = b2[0];
		else
		{
			if(c1 >=2)	
				removed1 = b1[0];
				removed2 = b1[1];
		}		 
	}
	int c = 0, co = 0;
	loop(i,n)
	{
		if(a[i] == 0)
			c++;
	}
	if(c == n)
		printf("0");
	c = 0;
	for(int i=n-1;i>=0;i--)
	{
		if(a[i] == removed1 || a[i] == removed2)
			c++;
		else
		{
			if(a[i] == 0)
			{
				if(c > 0)
		       		{
					printf("0");
					break;
				}
				else if(co > 0)
				{
					printf("0");
				}
			}
			else
			{
				co ++;
				printf("%d",a[i]);
			}
		}
	}
	if(c == n)
		printf("No such number");

	printf("\n");
	return 0;
}