#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int res[100][100];
int n;
int ans = 0;
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
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
int binarySearch(int arr[], int l, int r, int x)
//binarySearch(arr,0,n-1,valToBeSearched)
{
   if (r >= l)
   {
        int mid = l + (r - l)/2;
        // printf("%d ",mid);
 		if (arr[mid] == x)  
            return mid;
 
      	if (arr[mid] > x) 
            return binarySearch(arr, l, mid-1, x);
 		
 		return binarySearch(arr, mid+1, r, x);
   }
 
  	return -1;
}
void dfs(int vis[n+1],int s,int src,int path[n+1],int c,int dis)
{
	int *p=(int*)calloc(n+1,sizeof(int*));
	int *v=(int*)calloc(n+1,sizeof(int*));
	// printf("%d ",src);
	if(src!=s)
		vis[src]=1;
	for(int i=0;i<n+1;i++)
	{
		p[i]=path[i];
		v[i]=vis[i];
	}

	if(p[c-1]==s && c!=1) 
	{
		ans = ans + (c-2);
	}
	for(int i=0;i<n;i++)
	{
		if(res[src][i]>0 && !v[i])
		{
			p[c]=i;
			dfs(v,s,i,p,c+1,dis+res[src][i]);
		}
	}
}
int main()

{
	scanf("%d",&n);
	int a[n];
	loop(i,n)
		scanf("%d",&a[i]);
	int b[n], c[n];
	loop(i,n)
	{
		b[i] = i;
		c[i] = a[i];
	}
	loop(i,n)
	{
		loop(j,n)
			res[i][j] = 0;
	}
	bubbleSort(a, n, b);
	loop(i,n)
	{
		int val = binarySearch(a, 0, n-1, c[i]);
		// printf("%d ",val);
		if(i != val)
			res[i][val] = 1;
	}
	for(int i=0;i<n;i++)
	{
		int *vis=(int*)calloc(n+1,sizeof(int*));
		int *path=(int*)calloc(n+1,sizeof(int*));
		path[0]=i;
		dfs(vis,i,i,path,1,0);
		for(int j=0;j<n;j++)
		{
			res[j][i] = 0;
		}
	}
	printf("%d\n",ans);
	return 0;
}