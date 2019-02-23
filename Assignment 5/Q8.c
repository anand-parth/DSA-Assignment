#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)

void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
void bubbleSort(int a[], int n, int b[])
{
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				swap(&b[j], &b[j+1]);
			}
		}
	}
}
int main()
{
	int a, b, c;
	scanf("%d %d %d", &a, &b, &c);
	int m;
	scanf("%d", &m);
	int a1[m], b1[m];
	loop(i,m)
	{
		scanf("%d %d", &a1[i], &b1[i]);
	}
	bubbleSort(a1,m,b1);
	int res1[m], res2[m];
	int ct1 = 0 , ct2 = 0;
	loop(i,m)
	{
		if(b1[i] == 1)
			res1[ct1++] = a1[i];
		else
			res2[ct2++] = a1[i];
	}
	int count1 = 0, count2 = 0, ans = 0;
	while(a != 0)
	{
		ans = ans + res1[count1++];
		a--;
		if(count1 == ct1)
			break;
	}
	while(b != 0)
	{
		ans = ans + res2[count2++];
		b--;
		if(count2 == ct2)
			break;
	}
	while(c != 0)
	{
		if(count1 == ct1 && count2 ==ct2)
			break;
		else
		{
			c--;
			if(res1[count1] < res2[count2])
			{
				if(count1 != ct1)
				{
					ans = ans + res1[count1];
					count1++;
				}
				else
				{
					ans = ans + res2[count2];
					count2++;
				}
			}
			else
			{
				if(count2 != ct2)
				{
					ans = ans + res2[count2];
					count2++;
				}
				else
				{
					ans = ans + res1[count1];
					count1++;
				}
			}
		}
	}
	printf("%d %d\n", count1+count2, ans);


}