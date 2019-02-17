#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
int q[1000];
int front = -1, rear = -1;
int n;
void push(int x)
{
	if(front == -1)
	{
		front = 0;
	}							
	rear++;
	q[rear] = x;
}
int pop()
{
	if(front ==-1 || front > rear)
		return -1;
	else
		return q[front++];
}
bool Bipartite(int g[n][n])
{
	int source = 0;
	int arr[n];
	for(int i=0;i<n;i++)
		arr[i] = -1;
	arr[source] = 1;
	push(source);
	while(true)
	{
		int val = pop();
		if(val == -1)
			break;
		else
		{
			if(g[val][val] == 1)
				return false;
			for(int i=0;i<n;i++)
			{
				if(g[val][i] == 1 && arr[i] == -1)
				{
					arr[i] = 1 - arr[val];
					push(i);
				}
				else if(g[val][i] == 1 && arr[val] == arr[i])
					return false;
			}

		}
	}
	return true;
}
int main()
{
	scanf("%d", &n);
	int g[n][n];
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			scanf("%d", &g[i][j]);
		}
	}
	if(Bipartite(g))
		printf("Bipartite\n");
	else
		printf("Not Bipartite\n");
	return 0;
}