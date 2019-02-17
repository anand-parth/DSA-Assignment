#include<string.h>
#include<stdio.h>

int main()
{
    int n;
    scanf("%d", &n);
    int k=n-1, l=n-1;
    int v=n*n;
    int a[n][n];
    int lr = 0, lc = 0;
    while(k>=lr && l>=lc)
    {
    	for(int i=l;i>=lc;i--)
    	{
    		a[k][i] = v--;
    	}
    	k--;
    	for(int i=k;i>=lr;i--)
    	{
    		a[i][lc] = v--;
    	}
    	lc++;
    	if(k >= lr)
    	{
    		for(int i=lc;i<=l;i++)
    		{
    			a[lr][i] = v--;
    		}
    		lr++; 
    	}
       	if(l >= lc)
    	{
    		for(int i=lr;i<=k;i++)
    		{
    			a[i][l] = v--;
    		}
    		l--;
    	}
    }
    // a[n/2][n/2]=1;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%d " ,a[i][j]);
        }
        printf("\n");
    }
    return 0;
}