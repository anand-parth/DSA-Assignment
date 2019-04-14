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

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
int arr[100];
void insert(int len, int num)
{
	arr[len] = num;
}
int count(int num, int len)
{
	int ct = 0;
	loop(i,len)
	{
		if(arr[i] == num)
			ct++;
	}
	return ct;
}
int findid(int num, int len)
{
	loop(i,len)
	{
		if(arr[i] == num)
			return i;
	}
}
int main()
{
	int q;
	scan1(q);
	int len = 0, high = 0,low = 9999;
	loop(i,q)
	{
		int qt;
		scan1(qt);
		if(qt == 1)
		{
			int num;
			scan1(num);
			insert(len++, num);
			if(num > high)
				high = num;
			if(num < low)
				low = num;
			// print2(high,low);
		}
		else if(qt == 2)
		{
			int idh = findid(high, len);
			int idl = findid(low, len);
			int diff = arr[idh] - arr[idl];
			if(high == 0 && low == 9999)
				print1(-1);
			else
				print1(diff);
			high = 0, low = 9999;
			arr[idh] = -1, arr[idl] = -1;
		}
		else if(qt == 3)
		{
			int val = count(high,len);
			if(val == 0)
				print1(-1);
			else
				print1(val);
		}
		else if(qt == 4)
		{
			int val = count(low,len);
			if(val == 0)
				print1(-1);
			else
				print1(val);
		}
	}
	return 0;
}
		