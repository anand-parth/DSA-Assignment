#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int res[100][100];
int n;
int ans = 0;

typedef  struct
{
	int elem, pos;
} Tuple;

void swap(Tuple *x, Tuple *y)
{
	Tuple t= *x;
	*x = *y;
	*y = t;
}

void bubbleSort(Tuple a[], int n, int new[])
{
	int ct = 0;
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j].elem>a[j+1].elem)
			{
				new[j+1] = j;
				new[j] = j + 1;
				swap(&a[j], &a[j+1]);
			}
		}
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	Tuple t[n];
	for(int i=0;i<n;i++)
	{
		scanf("%d", &elem[i].elem);
	}
	return 0;
}