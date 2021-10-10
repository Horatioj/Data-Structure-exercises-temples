//第 4 周 / 编程题 - 在一个字符串中寻找某个子串
/*
本题目考虑字符数组形式的串。
【分析】

不断的从母串 str 中取出和子串长度相等的临时子串 temp，与子串 str2 进行比较。
如果没有找到子串，返回 -1；成功找到子串，返回子串首字母在母串中的位置，该位置从 0 开始。

样例输入：
abcdef
abcba
样例输出：
-1
*/

#include<iostream>
#include<string.h>
using namespace std;

char temp[2333];
void read(char* mo, char* so, int start){
    int i = 0;
    int lenofm = strlen(mo);
    int lenofs = strlen(so);
    for (i ;i < lenofs; i++)
        temp[i] = mo[i + start];
    temp[i] = '\0';
}

int determine(char* mo, char* so){
    int i = 0;
    int lenofm = strlen(mo);
    int lenofs = strlen(so);
    if (lenofm < lenofs)
        return -1;
    for (i; i <= lenofm - lenofs + 1; i++){
        read(mo, so, i);
        if (!strcmp(temp, so)){
            return i;
            break;
        }
    }
    return -1;
}

int main(){
    char mo[2333], so[2333];
    cin.getline(mo, 2333);
    cin.getline(so, 2333);
    if(mo == "\0") cout << "-1";
    else cout << determine(mo, so);
    return 0;
}