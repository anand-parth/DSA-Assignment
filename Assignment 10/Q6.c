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
	int high;
	int count;
}Tuple;
Tuple arr[100], Tuple arr2[100];
int size = 0, size2 = 0;
void swap(Tuple *x, Tuple *y)
{
    Tuple t = *x;
    *x= *y;
    *y = t;
}
void shiftUp(int id)
{
    int parent, tmp;
    if(id != 0)
    {
        parent = (id-1) / 2;
        if(arr[parent].high < arr[id].high)
        {
            swap(&arr[parent], &arr[id]);
            shiftUp(parent);
        }
    }
} 
void insertintoMaxHeap(int data,int ct)
{
    size++;
    arr[size-1].high = data;  
    arr[size-1].count = ct;  
    shiftUp(size-1);
}
void shiftUp2(int id)
{
    int parent, tmp;
    if(id != 0)
    {
        parent = (id-1) / 2;
        if(arr2[parent] > arr2[id])
        {
            swap(&arr2[parent], &arr2[id]);
            shiftUp2(parent);
        }
    }
} 
void insertintoMinHeap(int data)
{
    size2++;
    arr2[size2-1] = data;
    shiftUp2(size2-1);
}   
int main()
{
	int q;
	scan1(q);
	loop(i,q)
	{
		int qt;
		scan1(qt);
		if(qt == 1)
		{
			int num;
			scan1(num);
			int ct = 1;
			int flag = 0;
			loop(j,size)
			{
				if(arr[j].high == num)
				{	
					arr[j].count += 1;
					flag = 1;
					break;
				}
			}
			if(flag == 0)
				insertintoMaxHeap(num,ct);
		}
		else if(qt == 2)
		{

		}
		else if(qt == 3)
		{
			if(arr[0].count != 0)
				print1(arr[0].count);
			else
				print1(-1);
		}
		else if(qt == 4)
		{

		}
	}
	return 0;

}
		