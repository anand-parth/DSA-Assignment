#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<limits.h>

#define scan1(a) scanf("%d",&a)
#define scan2(b,c) scanf("%d %d", &b, &c)
#define scan3(d,e,f) scanf("%d %d %d", &d, &e, &f)
#define pn() printf("\n");
#define print1(a) printf("%d\n", a)
#define print2(a,b) printf("%d %d\n", a, b)
#define print3(a,b,c) printf("%d %d %d\n", a, b, c)

#define loop(i,n) for(int i=0;i<n;i++)
int a[100], value[100];

int main()
{
    int n;
    scan1(n);
    int root = -1;
    for(int i=1; i<=n; i++)
    {
        scan1(a[i]);
        if(i == a[i])
            root = i;
    }
    
    int val = 0, ans = 0;
    for(int i=1; i<=n; i++)
    {
        if(value[i] != 1)
        {
            val++;
            value[i] = val;
            int u = i;
            while(value[a[u]] == 0)
            {
                value[a[u]] = val;
                u = a[u];
            }

            if(value[a[u]] == val)
            {
                if(root == -1)
                    root = u;

                if(a[u] != root)
                {
                    ans++;
                    a[u] = root;
                }
            }
        }
    }
    print1(ans);
    for(int i=1; i<=n; i++)
        printf("%d ", a[i]);

    return 0;
}