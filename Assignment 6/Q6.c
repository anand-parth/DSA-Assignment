#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define loop(i,n) for(int i=0;i<n;i++)
int check(char a[],int n)
{
	int flag = 0;
	for(int i=0;i<n/2-1;i++)
	{
		if(a[i] <= a[i+1])
			continue;
		else
			flag = 1;
	}
	if(flag == 1)
		return 0;
	else
		return 1;
}
char  s[100];
int main()
{
	scanf("%s",s);
	int n =strlen(s);
	int ct = 0, gc = 0;
	char res[100];
	char resans[100];
	int count = 0;
	for(int i=0;i<n;i++)
	{
		for(int j=n-1;j>i;j--)
		{
			for(int k=i;k<=j;k++)
			{
				if(s[k] == s[j-(k-i)])
				{
					res[ct++] = s[k];
				}
				else
					break;
			}
			if(ct > gc)
			{
				if(check(res,ct))
				{
					loop(i,ct)
						resans[i] = res[i];
					gc = ct;
				}
			}
			if(ct == gc)
			{
				if(check(res,ct))
				{
					loop(i,ct)
					{
						if(res[i] == resans[i])
							continue;
						if(res[i] < resans[i])
						{
							loop(j,ct)
								resans[j] = res[j];
							break;
						}
					}
				}
			}
			ct = 0;
			loop(i,100)
				res[i] = '\0';
		}
	}
	if(strlen(resans) <= 2)
		printf("-1\n");
	else
		printf("%s ",resans);
	return 0;
}