#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char temp_str[30];    // 临时子串
 
void ReadStrUnit(char *str, char *temp_str, int idx, int len)  // 从母串中获取与子串长度相等的临时子串
{
    int index = 0;
    for(index; index < len; index++){
        temp_str[index] = str[idx+index];
    }
    temp_str[index] = '\0';
}
 
int GetSubStrPos(char *str1,char *str2){
    int idx = 0;
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    if( len1 < len2){
        printf("error 1 \n"); // 子串比母串长
        return -1;
    }
    while(1){
        ReadStrUnit(str1,temp_str,idx,len2);    // 不断获取的从 母串的 idx 位置处更新临时子串
        if(strcmp(str2,temp_str)==0)break;      // 若临时子串和子串一致，结束循环
        idx++;                                  // 改变从母串中取临时子串的位置
        if(idx>=len1)return -1;                 // 若 idx 已经超出母串长度，说明母串不包含该子串
    }
    return idx;    // 返回子串第一个字符在母串中的位置
}
 
int main(){ 
    char *str1;
    char *str2;
    str1 = (char*)malloc(100);
    str2 = (char*)malloc(100);
    scanf("%s", &str1);
    scanf("%s", &str2);
    int i = 0;
    i = GetSubStrPos(str1, str2);
    if(i < 0){
        printf("not found\n");
    }
    else{
        printf("i = %d\n",i);
    }
    return 0;
}