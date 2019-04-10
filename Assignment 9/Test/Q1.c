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
int time = 0;
int id = -1;
int vis[100];
// int minimum(int a[], int n, int e[])
// {
// 	int min = 9999;
// 	int minid = -1;
// 	int flag = 0;
// 	loop(i,n)
// 	{
// 		if(a[i] <= time && i != id)
// 		{
// 			if(a[i] < min && vis[i] != 1)
// 			{
// 				min = a[i];
// 				minid = i;
// 				flag = 1;
// 			}
// 		}
// 	}
// 	if(flag == 0)
// 	{
// 		int min = 9999;
// 		int minid = -1;
// 		loop(i,n)
// 		{	
// 			if(a[i] < min && vis[i] != 1)
// 			{
// 				min = a[i];
// 				minid = i;
// 			}
// 		}
// 		time = min;
// 		return minid;
// 	}
// 	return minid;
// }
int main()
{
	int n;
	scan1(n);
	int a[n], e[n], ec[n];
	int sum = 0;
	loop(i,n)
	{
		scan2(a[i], e[i]);
		ec[i] = e[i];
		sum = sum + e[i];
	}
	int t;
	scan1(t);
	sum = sum / t;
	int ans = 0;
	int ct = 0;
	for(int i=0; ;i++)
	{
		ct = 0;
		id = i % n;
		loop(j,n)
		{
			if(e[j] <= 0 && id == j)
			{
				id++;	
			}
		}
		loop(j,n)
		{
			if(e[j] == 0)
				ct++;
		}
		if(ct == n)
			break;
		id = id % n;
		if(time < a[id])
		{
			time = a[id];
		} 
		print1(id);
		if(e[id] < t)
		{
			time = time + e[id];
			e[id] = 0;
		}
		else
		{
			e[id] = e[id] - t;
			time = time + t;
		}
		if(e[id] <= 0)
		{
			vis[id] = 1;
			ans = ans + time - (ec[id] + a[id]);
			print2(ans,time);
		}
		if(time < a[(id+1)%3])
		{
			i = i - 1;
		}
	}
	print1(ans);
	return 0;
}