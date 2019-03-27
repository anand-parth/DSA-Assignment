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
// #define loop(i,a,n) for(int i=a;i<n;i++)
int q[1000];
int visited[1000];
int n;
int front = 0, rear = 0;
int dis[1000];
void push(int x)
{
	q[rear++] = x;
}
int pop()
{
	return q[front++];
}
void bfs(int v,int a[n][n],int n)
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
	int m,s,t;
	scan3(n,m,s);
	scan1(t);
	int a[n][n];
	loop(i,n)
		loop(j,n)
			a[i][j] = 0;
	loop(i,m)
	{	
		int u,v;
		scan2(u,v);
		a[u-1][v-1] = 1;
		a[v-1][u-1] = 1;
	}
	loop(i,n)
		visited[i] = 0;
	int dis_s[n], dis_t[n];
	bfs(s-1,a,n);
	loop(i,n)
	{
		dis_s[i] = dis[i];
		dis[i] = 0;
		visited[i] = 0;
	}
	bfs(t-1,a,n);
	loop(i,n)
	{
		dis_t[i] = dis[i];
	}
	int D = dis_s[t-1];
	int res= 0;
	loop(i,n)
	{
		loop(j,n)
		{
			if(a[i][j] != 1 && i != j)
			{
				if((dis_s[i]+dis_t[j]+1) >= D && (dis_s[j]+dis_t[i]+1) >= D)
					res++;
			}
		}
	}
	print1(res/2);
	return 0;
}
		