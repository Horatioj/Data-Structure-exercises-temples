//考虑char 数组表示的字符串，比如str[]=”   Abc  789   ”，
//现在要去掉该字符串头部、尾部的空格，中间的空格保留。

#include<iostream>
using namespace std;

char *trim(char* str);

int main(){
    char s[1000];

    cin.getline(s, 1000);
    cout << trim(s) << endl;
    return 0;
}

char *trim(char *str){
    char* point = str;
    while(*point != '\0'){
        point++;
    }
    point--;
    while(point >= str && *point == ' '){
        *point = '\0';
        point--;
    }
    point = str;
    while(*point == ' '){
        point++;
    }
    return point;
}