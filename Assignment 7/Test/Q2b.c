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
typedef struct Node
{
	int v;
	struct Node *x;
}Node;

Node *p,*l[100009];

int n, m, u, v, tms;
int cost[100];
int dfn[100], low[100];
int s[100];
int ins[100];
int ans, t, cnt=1;

void dfs(int u)
{
	dfn[u]=low[u]=++tms;
	ins[s[t++]=u]=1;
	int w;
	for (Node *p=l[u];p;p=p->x)
	{
		if (!dfn[w=p->v])
		{
			dfs(w);
			low[u]=min(low[u],low[w]);
		}
		else if (ins[w]) low[u]=min(low[u],dfn[w]);
	}
	if (low[u]==dfn[u])
	{
		int x=0,y=0;
		do
		{
			ins[w=s[--t]]=0;
			if (y>cost[w]) x=1,y=cost[w];
			else if (y==cost[w]) ++x;
		}
		while (u!=w);
		ans+=y;
	}
}

int main()
{
	scan1(n);
	for (int i=1;i<=n;++i) 
		scan1(cost[i]);
	scan1(m);
	for (int i=1;i<=m;++i)
	{
		scan2(u,v);
		p=(Node*)malloc(sizeof(Node));
		p->v=v,p->x=l[u],l[u]=p;
	}
	for (int i=1;i<=n;++i)
		if (!dfn[i]) 
			dfs(i);
	print2(ans,cnt);
	return 0;
}