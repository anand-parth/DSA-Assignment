#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define loop(i,n) for(int i=0;i<n;i++)
int check(char a[],int n)
{
	int flag = 0;
	for(int i=0;i<(n/2-1);i++)
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
	// char **ans;
	// ans = (char**)calloc(100,sizeof(char**));
	// loop(i,100)
	// 	ans[i] = (char*)calloc(100,sizeof(char*));
	// int count = 0;
	// for(int i=0;i<n;i++)
	// {
	// 	for(int j=n-1;j>i;j--)
	// 	{
	// 		for(int k=i;k<=j;k++)
	// 		{
	// 			if(s[k] == s[j-(k-i)])
	// 			{
	// 				res[ct++] = s[k];
	// 			}
	// 			else
	// 				break;
	// 		}
	// 		if(ct > gc)
	// 		{
	// 			printf("%s ",res);
	// 			gc = ct;
	// 		}
	// 		loop(i,ct)
	// 			res[i] = '\0';
	// 		ct = 0;
	// 	}
	// }
	// printf("%s ",resans);
	printf("%d",check(s,n));
	return 0;
}