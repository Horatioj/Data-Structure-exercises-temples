//����char �����ʾ���ַ���������str[]=��   Abc  789   ����
//����Ҫȥ�����ַ���ͷ����β���Ŀո��м�Ŀո�����

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