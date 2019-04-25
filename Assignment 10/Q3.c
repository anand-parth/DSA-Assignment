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
int arr[100], arr2[100];
int size = 0, size2 = 0;
void swap(int *x, int *y)
{
    int t = *x;
    *x= *y;
    *y = t;
}
void shiftUp(int id,int type)
{
    int parent, tmp;
    if(id != 0)
    {
        parent = (id-1) / 2;
        if(type == 1)
        {    
            if(arr[parent] < arr[id])
            {
                swap(&arr[parent], &arr[id]);
                shiftUp(parent,1);
            }
        }
        if(type == 0)
        {
            if(arr2[parent] > arr2[id])
            {
                swap(&arr2[parent], &arr2[id]);
                shiftUp(parent,0);
            }
        }    
    }
} 
void insertintoMaxHeap(int data)
{
    size++;
    arr[size-1] = data;
    shiftUp(size-1, 1);
}
void insertintoMinHeap(int data)
{
    size2++;
    arr2[size2-1] = data;
    shiftUp(size2-1, 0);
}   
void shiftDown(int id,int arr[])
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
        shiftDown(minid,arr);
    
}} 
void delete1()
{
    arr[0] = arr[size-1];
    size --;
    if(size > 0)
        shiftDown(0,arr);
}
void delete2()
{
    arr2[0] = arr2[size2-1];
    size2 --;
    if(size2 > 0)
        shiftDown(0,arr2);
}
int main()
{
    int n;
    scan1(n);
    double median = 0.0;
    loop(i,n)
    {
        int num;
        scan1(num);
        if(num > median)
            insertintoMinHeap(num);
        else
            insertintoMaxHeap(num);
        if(size - size2 >= 2)
        {
            insertintoMinHeap(arr[0]);
            delete1();
        }
        if(size2 - size >= 2)
        {
            insertintoMaxHeap(arr2[0]);
            delete2();
        }
        if(i % 2 == 0)
        {
            if(size < size2)
                median = arr2[0];
            else
                median = arr[0];
        }
        else
        {
            median = (double) (arr[0] + arr2[0])/2;
        }
        
        printf("%.1f\n",median);
    }
    return 0;
}
        