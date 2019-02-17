#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
int h[20000],c[20000];
int n;

int cost(int h_exp)
{
	int count = 0;
	for(int i=0;i<n;i++)
	{
		count += abs(h[i]-h_exp)*c[i];
	}
	return count;
}

int max_h()
{
	int max = 0;
	for(int i=0;i<n;i++)
	{
		if(h[i]>max)
			max = h[i];
	}
	return max;
}



int bin()
{
	int high = max_h()+1;
	int low = 0, ans = 100000;
	
	while(high > low)
	{
		int mid = (low+high)/2;
		
		int bm= (mid > 0) ? cost(mid-1):100000;
		int am=cost(mid+1);
		int m=cost(mid);
		
		// printf("%d %d %d ", bm, am , m);

		if(ans == m) 
			break;
		
		ans= (ans > m) ? m : ans;
		
		if(bm <= m)
		{
			// printf("A "); 
			high = mid-1;
		}
		else if(m >= am) 
		{
			// printf("B ");
			low = mid+1;
		}
	}
	return ans;
}

int main() 
{
	
	scanf("%d",&n);
	int i;
	loop(i,n)
		h[i] = i+1;
		// scanf("%d",&h[i]);
	loop(i,n)
		c[i] = i+1;
		// scanf("%d",&c[i]);
	
	printf("%d\n",bin());
	
	return 0;
}