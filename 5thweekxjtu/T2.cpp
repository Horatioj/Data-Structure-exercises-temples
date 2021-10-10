//第 5 周 / 编程题 - 最长的串
/*
编写一个函数，从传入的一个字符串中找出一个最长的一个子字符串， 输出该子字符串。
假设各个子串以回车作为结束符，空格为分隔符。

输入样例：

Life is not a problem to be solved but a reality to be experienced

输出样例：

experienced
*/

#include<stdio.h>
#include<string.h>
 
void findLongest(char str[])
{
    int currLen = 0, maxLen = 0, currStart = 0, MaxStart = 0;
    int i = 0, j = 0;
    for(i = 0; str[i]; i++)
    {
        if((str[i] >= 'a' && str[i] <= 'z') || (str[i] >= 'A' && str[i] <= 'Z'))
        {
            if(currLen == 0)//当前长度等于0时，说明一个单词刚刚查找完，此时的位置为
                currStart = i;//新单词的开始位置
            currLen++;
        }
        if(currLen > maxLen)//当前单词的长度大于最大值，进行赋值
        {
            maxLen = currLen;
            MaxStart = currStart;
        }
        if(str[i] == ' ')//遇到空格，即一个单词已经结束。
        {
            currLen = 0;
        }
    }
    for(j = MaxStart; j < MaxStart + maxLen; j++)
        printf("%c", str[j]);
}

int main()
{
    char str[10000];
    gets(str);
    findLongest(str);
    return 0;
}