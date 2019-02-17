#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)	
int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	double time[n];
	loop(i,n)
		scanf("%lf",&time[i]);
	double sum = 0.0;
	loop(i,n)
		sum += 1/time[i];
	printf("%lf", sum);
	double val = m/sum;
	// int v = val;
	// val = val + 1-(val - v);
	// v = val;
	// printf("%d ",v);
	printf("%lf ", ceil(val));
	return 0;	
}


// Logic is find work completed in 1 sec by taking reciprocals of times
// Then add them to get the total work. Divide by m to get time.