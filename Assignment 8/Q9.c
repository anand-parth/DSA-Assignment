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

int q[100];
int front = -1, rear = -1;
void check(int data)
{
    int i,j;
 
    for (i = 0; i <= rear; i++)
    {
        if (data <= q[i])
        {
            for (j = rear + 1; j > i; j--)
            {
                q[j] = q[j - 1];
            }
            
            q[i] = data;
            return;
        }
    }
    q[i] = data;
}
void insert(int data)
{
    if ((front == -1) && (rear == -1))
    {
        front++;
        rear++;
        q[rear] = data;
        return;
    }    
    else
        check(data);
    rear++;
}
int pop()
{
	return q[front++];
}
int top()
{
	return q[front];
}
int DecArray(int a[], int n)
{
	int sum = 0;
	loop(i,n)
	{
		if(!(front == rear) && top() < a[i])
		{
			int diff = a[i] - top();
			sum += diff;
			pop();
			insert(a[i]);
		}
		insert(a[i]);
		for(int i=front;i<=rear;i++)
			printf("%d ",q[i]);
		pn();
	}
	return sum;
}
int main()
{
	int n;
	scan1(n);
	int a[n];
	loop(i,n)
	{
		scan1(a[i]);
	}
	print1(DecArray(a,n));

	return 0;
}