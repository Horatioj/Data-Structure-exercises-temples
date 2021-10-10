#include<iostream>
using namespace std;

void BubbleSort(int a[], int n){          //10个整数升序排列
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if(a[j] > a[j+1]) {
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

void SelectionSort(int a[], int n){       //10个整数降序排列
    int i, j, temp;
    for(i = 0; i < n - 1; i++){
        for(j = 0; j < n - i - 1; j++){
            if(a[j] < a[j+1]){
                temp = a[j+1];
                a[j+1] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main(){
    int i;
    int list[10];
    cout << "请输入10个整数: ";
    for (i = 0; i < 10; i++){
        cin >> list[i];
    }
    BubbleSort(list, 10);
    for(i = 0; i < 10; i++){
        if(i!=9) cout << list[i] << " ";
        else cout << list[i] << "\n";
    }
    SelectionSort(list, 10);
    for(i = 0; i < 10; i++){
        if(i!=9) cout << list[i] << " ";
        else cout << list[i];
    }
    return 0;
}