#include<string.h>
#include<stdio.h>
#include<stdlib.h>

int main()
{
	int **a = (int **)calloc(5,sizeof(int*));
	for(int i=0;i<5;i++)
		a[i] = (int*)calloc(5,sizeof(int));
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
			a[i][j] = j*j;
		}
	}
	a = (int **)realloc(a,sizeof(int*)*10);
	for(int i=0;i<10;i++)
		*(a+i) = (int*)realloc(a[i],sizeof(int)*10);
	for(int i=5;i<10;i++)
		a[i] = (int*)calloc(10,sizeof(int));
	for(int i=0;i<10;i++)
	{
		for(int j=0;j<10;j++)
		{
			printf("%d ",a[i][j]);
		}
		printf("\n");
	}

	return 0;
}