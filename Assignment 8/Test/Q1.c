#include<stdio.h>
#include<stdlib.h>
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

int a[100]; 

int main()
{
	int n;
	scan1(n);
	int i, j, k;
	for(i=0;i<n;i++)
	{
		int t;
		scan1(t);
		int start = 0, end = i;
		int mid = (end - start) / 2;
		while(start != mid && mid != end)
		{
			 if (a[mid] > t)
                end = mid;
            else if (a[mid] <= t)
                start = mid;

            mid = start + (end - start)/2;
		}
		 for(j=mid; j < i; j++) 
		 {
            if (a[j] > t)
                break;
        }
        
        for(k = i; k >= j+1; k--)
              a[k] = a[k-1];
        a[j] = t;
   
        if(i%2 == 0)
            printf("%.1f\n", (float)a[i/2]); 
        else 
            printf("%.1f\n", (float)(a[i/2] + a[(i+1)/2])/2.0);
    }

	return 0;
}