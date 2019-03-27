#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)

#define pn() printf("\n");
#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)
#define loop(i,n) for(int i=0;i<n;i++)

int q[100];
int visited[100];
int n;
int front = 0, rear = 0;
int dis[100];
int a[100][100];
void push(int x)
{
	q[rear++] = x;
}
int pop()
{
	return q[front++];
}
void bfs(int v,int n)
{
	push(v);
	visited[v] = 1;
	while(front<rear)
	{
		v = pop();
		for(int i=0;i<n;i++)
		{	
			if(a[v][i] == 1 && visited[i] == 0)
			{
				push(i);
				visited[i] = 1;
				dis[i] = dis[v] + 1;
			}
		}
	}
}
int main()
{
	int x;
	scan2(n,x);
	loop(i,n)
	{
		loop(j,n)
		{
			a[i][j] = 0;
		}
	}
	loop(i,n-1)
	{
		int u,v;
		scan2(u,v);
		a[u-1][v-1] = 1;
		a[v-1][u-1] = 1;
	}
	int distance[n][n];
	loop(i,n)
	{
		loop(j,n)
		{
			visited[j] = 0;
			dis[j] = 0;
		}
		bfs(i,n);
		loop(j,n)
		{
			distance[i][j] = dis[j];
		}
	}
	int count = 0, minv = 9999;
	int A[100], B[100];
	int al,b;
	loop(i,n)
	{
		int ct = 0;
		loop(j,n)
		{
			if(a[i][j] == 1)
				ct++;
		}
		if(ct == 1 && i != 0)
		{
			al = distance[0][i];
			b = distance[x-1][i];
			if(b < al)
				if(i < minv)
					minv = i;		
		}
	}
	print1(distance[0][minv]*2);
	return 0;
}

// Find distance matrix which finds distance of all vertices to each other.
// Then see which are leaf node and check distance from Alice and Bob to those vertices.
// If Bob is nearer, then check if it is less than minv, update minv.