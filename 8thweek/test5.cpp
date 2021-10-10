#include<iostream>
//#include<cstdio>
using namespace std;

/*
bool isDigit(char a){
    if(a-'0'==0||a-'0'==1||a-'0'==2||a-'0'==3||a-'0'==4||a-'0'==5||a-'0'==6
    ||a-'0'==7||a-'0'==8||a-'0'==9) return true;
}

void testInt(string y){
    for(int i = 0; i < y.length(); i++){
        if(!isDigit(y[i])) 
        cout << "no integer" << endl;
        return;
    }
}*/

int overlap(int stu[], int i){
    //int num = read(stu);
    int num = 100;
    int flag1, flag2, flag3;
    for(int j = 0; j < num; j++){
        if(stu[i] == stu[j]) flag1 = 0;
        else flag1 = 1;
    }
    if(isdigit(stu[i]) != 0) flag2 = 1;
    else flag2 = 0;
    if(stu[i] > 0) flag3 = 1;
    else flag3 = 0;
    if((flag1+flag2+flag3)==3) return 1;
    else return 0;
}

int main(){
    int a, b, c;
    char d;
    cin >> d;
    cout << isdigit(d);
    return 0;
}

