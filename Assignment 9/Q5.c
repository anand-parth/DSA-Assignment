#include<stdio.h>
#include<stdlib.h>
#include<string.h>
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

int main()
{
	char s[100];
	scanf("%s",&s);
	char ct[26];
	int l = strlen(s);
	loop(i,26)
		ct[i] = 0;
	loop(i,l)
	{
		ct[s[i] - 97]++;
	}
	loop(i,26)
	{
		if(ct[i] > (l+1)/2)
		{
			printf("Not Possible\n");
			return 0;
		}
	}
	printf("Possible\n");

	return 0;
}