#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define loop(i,n) for(int i=0;i<n;i++)
int height[100], costarr[100];
int s;
int min = 9999;
int towht = 9999;
int towno = 9999;
void combinationUtil(int arr[],int n,int r,int index,int data[],int i);  
void printCombination(int arr[], int n, int r) 
{ 
    int *data = calloc(r,sizeof(int*));   
    combinationUtil(arr, n, r, 0, data, 0);
}
void combinationUtil(int arr[], int n, int r, int index, int data[], int i) 
{ 
    if (index == r) 
    {
    	int *temp = calloc(n,sizeof(int*));
		int cost = 0;
    	for (int j=0; j<r; j++) 
    	{
     		temp[data[j]] = s/r;  
        }
        for(int j=0;j<n;j++)
        	cost = cost + abs(height[j]-temp[j])*costarr[j];
        printf("%d ",cost);
        // Uncomment out above line to see cost values for different combinations.
        if(cost<min)
        {
        	min = cost;
        	towht = s/r;
        	towno = r;
        }
        return; 
    } 
    // printf("A ");
    if (i >= n)
    	return; 
  
    data[index] = i; 
    combinationUtil(arr, n, r, index+1, data, i+1); 
    combinationUtil(arr, n, r, index, data, i+1); 
} 
int main()
{
	int n;
	scanf("%d",&n);
	loop(i,n)
		scanf("%d",&height[i]);
	loop(i,n)
		scanf("%d",&costarr[i]);
	// printf("AA");
	s = 0;
	loop(i,n)
		s += height[i];
	int res[s];
	int len = 1;
	res[0] = 1;
	for(int i=2;i<=s/2;i++)
	{
		if(s%i == 0)
			res[len++] = i;
	}
	loop(i,len)
	{
		if(res[i]<=n)
		{
			printCombination(height, n, res[i]);
			// printf("\n*********\n");
			
		}
	}
	printf("%d %d %d\n",min, towno, towht);
	
	return 0;
}

// Logic is find out all possible combination and find add values of height,
// then find difference between heightarr and heightval which is s/r,
// where r denotes r possible nos. picked from n or nCr.
// Then take min of all such costs. Works till n = 25, complexity not that great.