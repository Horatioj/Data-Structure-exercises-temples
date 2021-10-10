/**考虑char 数组表示的正整数数字，比如"123"、"976"，
现在要将他们变为int型数字，
然后将两个数字作加法。
如输入
123
123
输出
246*/

#include<stdio.h>
int atoi(char a[])
{
    int i,n;
    n=0;
    for(i=0;a[i]>='0'&&a[i]<='9';++i)
        n=10*n+(a[i]-'0');
     return n;
}
int main()
{
    int n=0,m=0;
    char a[10],a1[10];
    gets(a);
    gets(a1);
    n=atoi(a);
    m=atoi(a1);
    printf("%d",n+m);
}