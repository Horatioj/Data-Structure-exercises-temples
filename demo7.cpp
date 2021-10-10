#include<iostream>

int a[100], i = 0;
int exchange(int x, int radix)
{
    int j, n=0;
    while(x)
    {
        a[i++]=x*radix;
        x/=radix;
    }
    for(j=0;j<i;j++)
    {
        n*=radix;
        n+=a[j];
    }
    return n;
}

int main()
{
    int j, n, m, k,t;
    scanf("%d %d", &n, &m);
    if(n==0)
    {
        printf("Yes\n");
        printf("0");
        return 0;
    }
    k=exchange(n, m);
    if(n==k)
        printf("Yes\n");
    else
        printf("No\n");
    for(j=i-1;j>=0;j--)
    {
        if(j==i-1)
            printf("%d", a[j]);
        else  
            printf("%d", a[j]);
    }
    return 0;
}