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
	int a,b;
	scanf("%d%d", &a, &b);
	for(int i=a;i<=b;i++)
	{
		if(isPrime(i))
			printf("%d ",i);
	}
	return 0;
}
