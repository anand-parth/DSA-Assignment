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
	*x = *y;
	*y = t;
}
void maxHeapify(int arr[], int i, int n)
{

	int l = 2*i + 1;
	int r = 2*i + 2;
	int smallest = i;
	if(l < n && arr[l] > arr[i])
		smallest = l;
	if(r < n && arr[r] > arr[smallest])
		smallest = r;
	if(smallest != i)
	{
		swap(&arr[i], &arr[smallest]);
		maxHeapify(arr,smallest,n);
	}
}
void convertMaxHeap(int arr[], int n)
{
	for(int i=n/2-1;i>=0;i--)
		maxHeapify(arr,i,n);
}
int main()
{
	int n;
	scan1(n);
	int arr[n];
	loop(i,n)
		scan1(arr[i]);
	convertMaxHeap(arr,n);
	loop(i,n)
		printf("%d ",arr[i]);
	return 0;
}
		