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
typedef struct node
{
	int sum;
	int id1, id2;
}Tuple;	

Tuple arr[100];
int size = 0;

void swap(Tuple *x, Tuple *y)
{
	Tuple t = *x;
	*x= *y;
	*y = t;
}
void shiftUp(int id)
{
    int parent;
    if(id != 0)
    {
        parent = (id-1) / 2;
        if(arr[parent].sum < arr[id].sum)
        {
            swap(&arr[parent], &arr[id]);
            shiftUp(parent);
        }
    }
}
void insertintoMaxHeap(int data, int i, int j)
{
    size++;
    arr[size-1].sum = data;
    arr[size-1].id1 = i;	
    arr[size-1].id2 = j;
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
        if(arr[l].sum >= arr[r].sum)
            minid = l;
        else
            minid = r;
    }
    if(arr[id].sum < arr[minid].sum)
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
	int b[n];
	loop(i,n)
		scan1(a[i]);
	loop(i,n)
		scan1(b[i]);
	insertintoMaxHeap(a[n-1] + b[n-1],n-1,n-1);
	for(int val=0;val<k;val++)
	{
		Tuple t = arr[0];
		print1(t.sum);
		int i = t.id1;
		int j = t.id2;
		delete();
		int suma = a[i-1] + b[j];
		int ct = 0;
		loop(i,size)
		{
			if(arr[i].id1 == i-1 && arr[i].id2 == j)
				ct++;
		}
		if(ct == 0)
			insertintoMaxHeap(suma,i-1,j);
		
		ct = 0;
		suma = a[i] + b[j-1];
		loop(i,size)
		{
			if(arr[i].id1 == i && arr[i].id2 == j-1)
				ct++;
		}
		if(ct == 0)
			insertintoMaxHeap(suma,i,j-1);
	}

	return 0;
}
		