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
#define min(a,b) (a<b)?a:b		

char a[100];
int top = -1;
void push(char x)
{
	a[++top] = x;
}
char pop()
{	
	if(top == -1)
		return '\0';
	else
		return a[top--];
}
void print()
{
	for(int i=top;i>=0;i--)
		printf("%c ",a[i]);	
	pn();
}
int main()
{
	char s[100];
	scanf("%s",s);
	loop(i,strlen(s))
	{
		if(s[i] == '(' || s[i] == '{' || s[i] == '[')
		{
			push(s[i]);	
		}	
		else
		{
			char val = pop();
			if(val == '\0')
			{
				printf("False\n");
				return 0;
			}
			else
			{
				if(val == '(' && s[i] == ')' || val == '[' && s[i] == ']' || val == '{' && s[i] == '}')
				{
					pn();
					continue;
				}
				else
				{				
					printf("False\n");
					return 0;
				}
			}
		}
	}
	printf("True\n");
	return 0;
}