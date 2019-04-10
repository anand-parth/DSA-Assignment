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
int stack[100];
int st2[100];
int top = 0, top2 = 0;
void push(int x)
{
	stack[top++] = x;
	if(top2 == 0)
		st2[top2++] = x;
	else
	{
		if(x < st2[top2-1])
		st2[top2++] = x;
	}
}
int pop()
{
	if(top == 0)
	{
		return -1;
	}
	if(stack[top-1] == st2[top2-1])
		st2[--top2];
	return stack[--top];
}
int minimum()
{
	if(top == 0)
	{
		return -1;
	}
	int val = st2[top2-1];
	return val;
}
int main()
{
	int c;
	while(c != -1)
	{
		scan1(c);
		if(c == 1)
		{
			int num;
			scan1(num);
			push(num);
		}
		if(c == 2)
		{
			int val = pop();
			if(val == -1)
			{
				printf("Empty Stack\n");
				return 0;
			}	
			else
				print1(val);
		}
		if(c == 3)
		{
			int val = minimum();
			if(val == -1)
			{
				printf("Empty Stack\n");
				return 0;
			}
			print1(val);
		}	
	}
	return 0;
}