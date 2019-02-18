#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

int main()
{
    int n;
    scanf("%d", &n);

    int h[n], c[n];
    int m = 0;
    for(int i=0;i<n;i++)
    {
        scanf("%d", &h[i]);
        m += h[i];
    }

    for(int i=0;i<n;i++)
    {
        scanf("%d", &c[i]);
    }

    int limit = 1<<n;
    int cost = INT_MAX, towers = 0, height = 0;
    for(int i=0;i<limit;i++)
    {
        int num = 0;
        for(int j=0;j<n;j++)
        {
            int bit = (1<<j) & i;
            // printf("%d ", bit);
            if(bit)
            {
                num++;
            }
        }
        if(num != 0 && num <= n && m%num == 0)
        {
            int k = m/num;
            int sum = 0;
            for(int j=0;j<n;j++)
            {
                int bit = (1<<j) & i;
                if(bit)
                {
                    sum += abs(h[j]-k)*c[j];
                }
                else
                {
                    sum += c[j]*h[j];
                }
            }
            printf("%d ",sum);
            if(sum < cost)
            {
                cost = sum;
                towers = num;
                height = k;
            }
        }
    }
    printf("%d %d %d\n", cost, towers ,height);
}