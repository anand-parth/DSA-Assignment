#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
int inv = 0;
int arr[100];
int cnt = 0;
int invCnt(int l, int m, int r)
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
        {
            arr[k] = b[j++]; 
        	inv += (n1-i);
        }
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
    // printf("%d ",inv);
}

int mergeSort(int l, int r)
{
	if(l<r)
	{
		int m = (r+l)/2;
		printf("1) M=%d L=%d R=%d\n",m,l,r);
		printf("A\n");
		mergeSort(l, m);
		printf("B\n");
		mergeSort(m+1, r);
		printf("2) M=%d L=%d R=%d\n",m,l,r);
		invCnt(l, m, r);
	}

}
int main()
{
	int n;
	scanf("%d", &n);
	loop(i,n)
		scanf("%d", &arr[i]);
	mergeSort(0,n-1);
	printf("%d\n",inv);
	return 0;
}