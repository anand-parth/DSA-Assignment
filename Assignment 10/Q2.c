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
int arr[100];
int size = 0;
void swap(int *x, int *y)
{
	int t = *x;
	*x= *y;
	*y = t;
}
void shiftUp(int id)
{
    int parent, tmp;
    if(id != 0)
    {
        parent = (id-1) / 2;
        if(arr[parent] < arr[id])
        {
            swap(&arr[parent], &arr[id]);
            shiftUp(parent);
        }
    }
} 
void insertintoMaxHeap(int data, int arr[])
{
    size++;
    arr[size-1] = data;
    shiftUp(size-1);
}
void shiftDown(int id)
{
    int minid, tmp;
    int l = 2*id + 1;
    int r = 2*id + 2;
    if(r >= size)
    {
        if(l >= size)
            return;
        else
            minid = l; 
    }
    else
    {
        if(arr[l] >= arr[r])
            minid = l;
        else
            minid = r;
    }
    if(arr[id] < arr[minid])
    {
        swap(&arr[minid],&arr[id]);
        shiftDown(minid);
    }
} 
void delete()
{
    arr[0] = arr[size-1];
    size --;
    if(size > 0)
        shiftDown(0);
}
int main()
{
	int n, k;
	scan2(n,k);
    int a[n];
	loop(i,n)
	{
        scan1(a[i]);
        insertintoMaxHeap(a[i], arr);        
    }
    int ans = 0;
    loop(i,k)
    {
        int elem = arr[0];
        ans = ans + elem;
        delete();
        insertintoMaxHeap(elem/2,arr);
    }
    print1(ans);
 	return 0;

}