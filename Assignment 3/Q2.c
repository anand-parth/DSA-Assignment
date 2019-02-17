#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define loop(i,n) for(int i=0;i<n;i++)
int main()
{
	char s[1000];
	scanf("%s",s);
	int m;
	scanf("%d",&m);
	loop(i,m)
	{
		int f,r,k;
		scanf("%d %d %d", &f, &r, &k);
		while(k!=0)
		{
			char t = s[f-1];
			char t2;
			for(int i=f;i<r;i++)
			{
				t2 = s[i];
				s[i] = t;
				t = t2;
			}
			s[f-1] = t;
			k--;
		}
	}
	printf("%s",s);




	return 0;
}