#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
	int **p;
	p = (int **)calloc(4,sizeof(int*));
	for(int i=0;i<4;i++)
		p[i] = (int *)calloc(5,sizeof(int));
	int a[]= {1,2,3,4,5};
	p[1] = a;
	for(int i=0;i<5;i++)
		printf("%d ",p[1][i]);
	return 0;
}