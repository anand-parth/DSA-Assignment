#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int res[100][100];
typedef struct 
{
	int id,dis;
	
}Node;
void swap(Node *x, Node *y)
{
	Node t= *x;
	*x = *y;
	*y = t;
}
void bubbleSort(Node a[], int n)
{
	int ct = 0;
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j].dis>a[j+1].dis)
			{
				swap(&a[j], &a[j+1]);
			}
		}
	}
}
int main()
{
	int n;
	scanf("%d", &n);
	Node a[n];
	loop(i,n)
	{
		scanf("%d", &a[i].dis);
		a[i].id = i+1;
	}
	loop(i,n+1)
	{
		loop(j,n+1)
		{
			res[i][j] = 0;
		}
	}
	if(n<=2)
	{
		printf("-1\n");
		return 0;
	}
	bubbleSort(a,n);
	if(a[0].dis != 0)
	{
		printf("-1\n");
		return 0;	
	}
	int prev = 0, curr = 1;
	int x =-1, y = -1;
	while(curr < n)
	{
		if(a[curr].dis == a[curr-1].dis)
		{
			x = a[curr-1].id;
			y = a[curr].id;
		}
		else
			prev = curr-1;

		if(a[curr].dis != (a[prev].dis)+1)
		{
			printf("-1\n");
			return 0;
		}
		res[a[prev].id][a[curr].id] = 1;
		res[a[curr].id][a[prev].id] = 1;
		curr++;
	}
	// For the case when graph given is a path.
	if(x == -1 || y == -1)
	{
		printf("-1\n");
		return 0;
	}
	else
	{
		res[x][y] = 1;
		res[y][x] = 1;	
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			if(res[i][j] == 1)
				printf("%d %d\n",i,j);
		}
	}
	return 0;
}