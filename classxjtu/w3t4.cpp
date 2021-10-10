/**请用“分解质因子”方法求出最小公倍数。
如
输入：2 4
输出：4*/


#include<stdio.h>
int gcd(int x,int y);    
int hcd(int x,int y,int z); 
int main()   
{
    int a,b,g,h;
    scanf("%d %d",&a,&b);
    if(a == 0||b == 0)
    {
        printf("输入数据错误！\n");
        return 1;
    }
    g = gcd(a, b);    
    h = hcd(a, b, g);    
    printf("%d\n",h);
    return 0;
}

int gcd(int x,int y)
{
    int r;
    do
    {
        r = x % y;
        x = y;
        y = r;
    }while(r != 0);
    return x;
}

int hcd(int x,int y,int z)
{
    return (x * y / z);
}