#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define loop(i,n) for(int i=0;i<n;i++)
int main()
{
	char s[10];
	scanf("%s",s);
	int ct[26]={0};
	loop(i,strlen(s))
		ct[s[i]-97]++;
	int count = 0;
	loop(i,26)
	{
		if(ct[i] == 1)
		{
			ct[i] = 0;
			count++;
		}
	}
	if(count!=1 && strlen(s)%2!=0)
		printf("NO\n");
	else if(count>0 && strlen(s)%2==0)
		printf("NO\n");
	else
	{
		count = 0;
		loop(i,26)
		{
			if(ct[i]%2==0)
				count++;
		}
		if(count!=26)
			printf("NO\n");
		else
			printf("YES\n");
	}
	return 0;
}