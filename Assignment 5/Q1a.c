#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
int max(int a[], int n)
{
	int v = a[0];
	loop(i,n)
	{
		if(a[i] > v)
			v = a[i];
	}
	return v;
}
void bubbleSort(int a[], int n, int b[])
{
	int ct = 0;
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				swap(&b[j], &b[j+1]);		
			}
		}
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	loop(i,t)
	{
		int n;
		scanf("%d",&n);
		int a[n];
		int b[n];
		loop(i,n)
		{
			scanf("%d %d", &a[i], &b[i]);
		}
		bubbleSort(a, n, b);
		int g1 = b[0];
		int g2 = -1;
		int c1[n], c2[n];
		loop(i,n)
		{
			c1[i] = 0;
			c2[i] = 0;
		}
		c1[0] = 1;
		for(int i=1;i<n;i++)
		{
			if(g1 < a[i])
			{
				c2[i] = 1;
				c1[i] = 1;
			}
			else
			{
				// printf("%d B \n",i);
				c1[i] = 1;
				if(b[i] > g1)
					g1 = b[i+1];
			}
		}
		int count = 0;
		loop(i,n)
		{
			if(c1[i] == 1)
				count ++;
		}
		if(count == n)
			printf("-1");
		else		
		{
			loop(i,n)
			{
				int c =0;
				if(c1[i] == 1 && c2[i] == 0)
					printf("IM ");
				if(c2[i] == 1 && c2[i] == 0) 
					printf("CA ");
				else
				{
					c++;
					if(c%2==1)
						printf("CA ");
					else
						printf("IM ");

				}
			}
		}
		printf("\n");
	}

	return 0;
}

// 3
// 2
// 5 5
// 2 3
// 3
// 3 5
// 2 3
// 2 3
// 3
// 3 3
// 4 4
// 5 5
