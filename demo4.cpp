//用“分解质因子”方法求最小公倍数

#include<stdio.h>
int gcd(int x,int y);     //最大公约数声明
int hcd(int x,int y,int z);     //最小公倍数声明
int main()
{
    int a,b,g,h;
    scanf("%d %d",&a,&b);
    if(a == 0||b == 0)
    {
        printf("输入数据错误！\n");
        return 1;
    }
    g = gcd(a, b);     //最大公约数调用
    h = hcd(a, b, g);     //最小公倍数函数调用
    printf("两个数的最小公倍数是：%d\n",h);
    return 0;
}
//求最大公约数
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
//求最小公倍数
int hcd(int x,int y,int z)
{
    return (x * y / z);
}