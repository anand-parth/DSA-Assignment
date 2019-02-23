#include<stdio.h>
#define loop(i,n) for(int i=0;i<n;i++)
void swap(int *x, int *y)
{
	int t= *x;
	*x = *y;
	*y = t;
}
void bubbleSort(int a[], int n)
{
	loop(i,n-1)
	{
		loop(j,n-1-i)
		{
			if(a[j]>a[j+1])
			{
				swap(&a[j], &a[j+1]);
				
			}
		}
	}
}
void selectSort(int a[], int n)
{
	int tmp;
	for(int i=0;i<n-1;i++)
	{
		tmp = i;
		for(int j=i+1;j<n;j++)
		{
			if(a[j] < a[tmp])
				tmp = j;
			swap(&a[tmp], &a[i]);
		}
	}
}
void merge(int arr[], int l, int m, int r)
{
	int n1 = m-l + 1;
	int n2 = r-m;

	int f[n1], b[n2];
	
	loop(i,n1)
		f[i] = arr[l+i];
	loop(i,n2)
		b[i] = arr[m+1+i];

	int k = l;
	int i = 0, j = 0;
	while (i < n1 && j < n2) 
    { 
        if (f[i] <= b[j]) 
            arr[k] = f[i++]; 
        else
            arr[k] = b[j++]; 
        k++; 
    }
	while (i < n1) 
    { 
        arr[k++] = f[i++]; 
    } 
    while (j < n2) 
    { 
        arr[k++] = b[j++]; 
    } 

}
void mergeSort(int arr[], int l, int r)
{
	if(l<r)
	{
		int m = l + (r-l)/2;
		mergeSort(arr, l, m);
		mergeSort(arr, m+1, r);

		merge(arr, l, m, r);
	}
}

int main()
{
	int n;
	scanf("%d",&n);
	int a[n];
	loop(i,n)
		scanf("%d",&a[i]);
	// bubbleSort(a,n);
	// selectSort(a,n);
	// mergeSort(a,0,n-1);
	return 0;
}