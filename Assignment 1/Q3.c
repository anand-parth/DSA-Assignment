#include<string.h>
#include<stdio.h>
int isPrime(int n)
{
    if(n<=1)
        return 0;
    if(n<=3)
        return 1;
    if(n%2==0 || n%3==0)
        return 0;
    for(int i=5;i*i<=n;i=i+6)
        if(n%i==0 || n%(i+2)==0)
            return 0;
    return 1;
}
int main()
{
    int n;
    scanf("%d", &n);
    int k=n-1,l=n-1;
    int ct=0;
    int arr[n*n];
    for(int i=1; ;i++)
    {
        if(isPrime(i))
            arr[ct++] = i;
        if(ct == n*n)
            break;
    }
    int a[n][n];
    int lr = 0;
    int lc = 0;
    ct=n*n-1;
    while(k>=lr && l>=lc)
    {
    	for(int i=l;i>=lc;i--)
    	{
    		a[k][i] = arr[ct--];
    	}
    	k--;
    	for(int i=k;i>=lr;i--)
    	{
    		a[i][lc] = arr[ct--];
    	}
    	lc++;
    	if(k >= lr)
    	{
    		for(int i=lc;i<=l;i++)
    		{
    			a[lr][i] = arr[ct--];
    		}
    		lr++; 
    	}
       	if(l >= lc)
    	{
    		for(int i=lr;i<=k;i++)
    		{
    			a[i][l] = arr[ct--];
    		}
    		l--;
    	}
    }
    // a[n/2][n/2]=arr[0];
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
