#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define loop(i,n) for(int i=0;i<n;i++)
int main()
{
	char t[1000];
	char p[1000];
	scanf("%s",t);
	scanf("%s",p);
	int n;
	scanf("%d", &n);
	int a[n];
	loop(i,n)
		scanf("%d", &a[i]);
	int ct[n];
	loop(i,n)
		ct[i] = 0;
	loop(i,n)
	{
		loop(j,strlen(p))
		{
			if(t[i] == p[j])
			{
				ct[i] = 1;
			}
		}
	}
	int count = 0;
	loop(i,n)
	{
		if(ct[a[i]-1]!=1)
			count++;
		else
			break;
	}
	printf("%d\n",count);
	return 0;
}