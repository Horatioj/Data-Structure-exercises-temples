/**���á��ֽ������ӡ����������С��������
��
���룺2 4
�����4*/


#include<stdio.h>
int gcd(int x,int y);    
int hcd(int x,int y,int z); 
int main()   
{
    int a,b,g,h;
    scanf("%d %d",&a,&b);
    if(a == 0||b == 0)
    {
        printf("�������ݴ���\n");
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