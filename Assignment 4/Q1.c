#include<stdio.h>
#include<stdlib.h>
#define loop(i,n) for(int i=0;i<n;i++)
int main()
{
	int n,s;
	scanf("%d %d",&n,&s);
	int a[n];
	loop(i,n)
		scanf("%d", &a[i]);
	int val = 0, valres = 0, ct = 1;
	while(s>0)
	{
		valres = val;
		val = 0;
		for(int i=0;i<ct;i++)
		{
			val = val + a[i] + (i+1)*ct;
		}
		s = s-val;
		if(s < 0)
		{
			s = s+val;
			ct--;
			break;
		}
		else
		{
			s = s+val;
			ct++;
		}
	}
	printf("%d %d\n",ct,valres);


	return 0;
}