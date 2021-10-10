//通过了第四周第七题

#include<iostream>
using namespace std;
int main(){
    int k = 0;
    cin >> k;
    if( k <= 0 || k >10000){
        return 0;
    }
    int* str; //存储数组
    str = new int[k];
    int max = 0, maxi = 0, maxj = 0; //存储最大值，最大值头尾索引
    int sum = 0; //存储当前子序和
    bool t = 0;
    for(int i = 0; i < k; i++){
        cin >> str[i];
        if(str[i] >= 0){
            t = 1;
        }
    }
    if(!t){
        cout << 0 << ' ' << str[0] << ' ' << str[k-1];
        return 0;
    }
    for(int i = 0; i < k; i++){
        sum = str[i];
        if(sum > max){
            max = sum;
            maxi = i;
            maxj = i;
        }
        for(int j = i + 1; j < k; j++){
            sum = sum + str[j];
            if(sum > max){
                max = sum;
                maxi = i;
                maxj = j;
            }
        }
    }
    cout << max << ' ' <<  maxi << ' ' << maxj << endl;
    return 0;
}