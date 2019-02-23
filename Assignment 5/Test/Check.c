#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int a[100];
int n;
int res[100][100];
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
void I(int key)
{
	for(int i=0;i<n-1;i++)
	{
		if((a[i] <= key && a[i+1] >= key))
		{
			// printf("%d A ",i);
			int t = key;
			int t2;
			for(int j=i+1;j<n+1;j++)
			{
				t2 = a[j];
				a[j] = t;
				t = t2;
				// a[j+1] = a[j];
			}
			break;
		}
		else if(a[0] >= key)
		{
			// printf("%d B ",i);
			int t = key;
			int t2;
			for(int j=0;j<n+1;j++)
			{
				t2 = a[j];
				a[j] = t;
				t = t2;
				// a[j+1] = a[j];
			}
			break;
		}
		else if(a[n-1] <= key)
		{
			// printf("%d C ",i);
			a[n] = key;
			break;
		}
	}
	n = n + 1;
}
void D(int val)
{
	int ct = 0;
	for(int i=0;i<n;i++)
	{
		if(a[i] == val)
		{
			a[i] = -1;
			break;
		}
	}
	int b[n];
	loop(i,n)
	{
		if(a[i] != -1)
		{
			b[ct++] = a[i];
		}
	}
	loop(i,ct)
		a[i] = b[i];
	n = ct;
}
void S(int v1, int v2)
{
	int i1, i2;
	loop(i,n)
	{
		if(a[i] == v1)
			i1 = i;
		if(a[i] == v2)
			i2 = i;
	}
	int t = a[i1];
	a[i1] = a[i2];
	a[i2] = t;
}
void P()
{
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				
			}
		}
	}

}
// void print()
// {
// 	loop(i,n)
// 		printf("%d ",a[i]);
// 	printf("\n");
// }
void print(int row)
{
	for(int j=0;j<n;j++)
	{
		res[row][j] = a[j];
	}
}
int main()
{
	scanf("%d",&n);
	loop(i,n)
		scanf("%d",&a[i]);
	int l;
	scanf("%d",&l);
	loop(i,l)
	{
		loop(j,100)
		{
			res[i][j] = 0;
		}
	}
	for(int k=0;k<13;k++)
	{
		char c;
		scanf("%c", &c);
		printf("A\n");
		if(c == 'I')
		{
			int x;
			scanf("%d",&x);
			I(x);
			print(k);
		} 
		else if(c == 'D')
		{
			int y;
			scanf("%d",&y);
			D(y);
			print(k);
		}
		else if(c =='S')
		{
			int a,b;
			scanf("%d %d", &a, &b);
			S(a, b);
			print(k);				
		}
		else if(c =='P')
		{
			P();
			print(k);
		}
	}

	loop(i,l)
	{
		loop(j,n)
		{
			if(res[i][j] != 0)
				printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	return 0;																																																																																																																																													
}

