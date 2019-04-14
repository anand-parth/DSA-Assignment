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
int a[100];
typedef struct
{
	int beg;
	int end;
}Tuple;
Tuple findid(int n)
{
	Tuple t;
	int ct = 0, ctmax = 0;
	int id;
	loop(i,n)
	{
		if(a[i] == 0)
			ct++;
		else
		{
			if(ct > ctmax)
			{
				ctmax = ct;
				id = i;
			}
			ct = 0;
		}
	}
	if(ct > ctmax)
	{
		ctmax = ct;
		id = n;
	}
	t.beg = id - ctmax;
	t.end = id;
	if(ct == n)
		t.end = n;
	return t;
}
int main()
{
	int n, k;
	scan2(n,k);
	char s[100];
	scanf("%s",s);
	int count = 0;
	loop(i,k)
	{
		int start = findid(n).beg;
		int end = findid(n).end;
		if((end-start) %2 == 0)
		{
			if(s[count] == 'R')
				a[(start+end)/2] = i+1;
			else
				a[(start+end)/2 - 1] = i+1; 
		}
		else
			a[(start+end) / 2] = i+1;
		count++;
	}
	int q;
	scan1(q);
	loop(i,q)
	{
		int pos;
		scan1(pos);
		if(a[pos-1] == 0)
			print1(-1);
		else
			print1(a[pos-1]);
	}
	return 0;
}
		