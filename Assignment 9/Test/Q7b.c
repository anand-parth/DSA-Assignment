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

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int a[100][100];
int dis[100];
int vis[100];
int pred[100];
int cost[100][100];
void dijkstra(int n, int src)
{
	int count, mindistance, nextnode;

	loop(i,n)
	{
		dis[i] = cost[src][i];
		pred[i] = src;
		vis[i] = 0;
	}
	dis[src] = 0;
	vis[src] = 1;
	count = 1;
	while(count < n-1)
	{
		mindistance=9999;
		for(int i=0;i<n;i++)
			if(dis[i] < mindistance && !vis[i])
			{
				mindistance = dis[i];
				nextnode = i;
			}
			
			//check if a better path exists through nextnode			
			vis[nextnode]=1;
			for(int i=0;i<n;i++)
				if(! vis[i])
					if(mindistance+cost[nextnode][i]< dis[i])
					{
						dis[i]=mindistance+cost[nextnode][i];
						pred[i]=nextnode;
					}
		count++;
	}

}
int main()
{
	int n,m;
	scan2(n,m);
	loop(i,n)
	{
		loop(j,n)
		{
			a[i][j] = 0;
		}
	}

	loop(i,m)
	{
		int u,v,price;
		scan3(u,v,price);
		a[u][v] = price;
	}

	loop(i,n)
	{
		loop(j,n)
		{
			if(a[i][j] == 0)
				cost[i][j] = 9999;
			else
				cost[i][j] = a[i][j];
		}
	}

	int t;
	scan1(t);
	loop(i,t)
	{
		int u, v, c;
		scan3(u,v,c);
		dijkstra(n,u);
		loop(j,n)
		{
			vis[j] = 0;
			pred[j] = 0;
			dis[j] = 0;
		}
	}
	return 0;
}