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
// #define loop(i,a,n) for(int i=a;i<n;i++)

#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
void swap(int *x, int *y)
{
	int t = *x;
	*x= *y;
	*y = t;
}
void MinHeapify(int arr[], int i, int n)
{
	int l = 2*i + 1;
	int r = 2*i + 2;
	int smallest = i;
	if (l < n && arr[l] < arr[i]) 
        smallest = l; 
    if (r < n && arr[r] < arr[smallest]) 
        smallest = r; 
    if (smallest != i) 
    { 
        print2(arr[i], arr[smallest]);
        swap(&arr[i], &arr[smallest]); 
        MinHeapify(arr, smallest, n); 
    } 
}
void convertMinHeap(int arr[], int n) 
{ 
    for (int i = (n/2 - 1); i >= 0;i--) 
        MinHeapify(arr, i, n); 
}  
int main()
{
	int n;
	scan1(n);
	int a[n], t[n];
	loop(i,n)
	{
    	scan1(a[i]);
        t[i] = a[i];
    }
    convertMinHeap(a,n);
    loop(i,n)
        print1(a[i]);
    loop(i,n)
    {
        if(a[i] != t[i])
        {
            printf("False\n");
            return 0;
        }
    }
    printf("True\n");
	return 0;
}