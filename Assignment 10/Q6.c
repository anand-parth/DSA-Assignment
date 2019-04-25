#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>
#include<string.h>

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
int retmax(int len)
{
	int max = 0;
	loop(i,len)
	{
		if(arr[i] > max)
			max = arr[i];
	}
	return max;
}
int retmin(int len)
{
	int min = 9999;
	loop(i,len)
	{
		if(arr[i] < min && arr[i] != -1)
			min = arr[i];
	}
	return min;
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
		char s[100];
		scanf("%s",s);
		int qt;
		if(strlen(s) == 4)
		{
			if(s[0] == 'D')
				qt = 2;
			if(s[0] == 'P')
				qt = 1;
		}
		else
		{
			if(s[5] == 'H')
				qt = 3;
			if(s[5] == 'L')
				qt = 4;
		}
		if(qt == 1)
		{
			int num;
			scan1(num);
			insert(len++, num);
		}
		else if(qt == 2)
		{
			int high = retmax(len);
			int low = retmin(len);
			int idh = findid(high, len);
			int idl = findid(low, len);
			int diff = arr[idh] - arr[idl];
			if(high != 0 && low != 9999)
			{
				if(high != low)
					print1(high - low);
				else
					print1(0);
			}
			else
				print1(-1);
			arr[idh] = -1, arr[idl] = -1;
		}
		else if(qt == 3)
		{
			int high = retmax(len);
			int val = count(high,len);
			if(val == 0)
				print1(-1);
			else
				print1(val);
		}
		else if(qt == 4)
		{
			int low = retmin(len);
			int val = count(low,len);
			if(val == 0)
				print1(-1);
			else
				print1(val);
		}
	}
	return 0;
}
		