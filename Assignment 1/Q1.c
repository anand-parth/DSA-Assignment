#include<string.h>
#include<stdio.h>

int main()
{
	int n;
	scanf("%d", &n);
    int a[n][n];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		scanf("%d" ,&a[i][j]);
    	}
    }
    int ct=0;
    int m1=a[0][0],m2=a[0][0];
    for(int i=0;i<n;i++)
    {
    	for(int j=0;j<n;j++)
    	{
    		if(a[i][j]<=m1)
    			m1=a[i][j];
    		if(a[j][i]>=m2)
    			m2=a[j][i];
    	}
    	if(m1==m2)
    	{
    		printf("%d\n" ,m1);
    		ct++;
    		break;
    	}
	} 
    	if(ct==0)
    		printf("No saddle point");
    
    return 0;
}
