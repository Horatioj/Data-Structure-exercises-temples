//设计一个队列，将任意n个整数入队（n>2）
//再将2个元素出队，随后将11和12入队，并再次输出队列所有元素
/*
输入输出格式：
输入：n个整数（n>2）
输出：队列中的所有元素

样例：

6

1 2 3 4 5 6

3 4 5 6 11 12
*/

#include<stdio.h>
int main(){
    int a[100];
    int i, n;
    scanf("%d", &n);
    if(n <= 2) return 0;
    for(i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    a[n] = 11;
    a[n+1] = 12;
    for(i = 2; i <= n + 1; i++){
        if(i == n + 1)printf("%d", a[i]);
        else printf("%d ", a[i]);
    }
    return 0;
}