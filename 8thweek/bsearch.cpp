#include<iostream>
using namespace std;

struct rec{
    int n;
    int num;
}list[100];

void binary_search(struct rec list[], int length, int key){
    int low, mid, high, find;
    low = 0; high = length - 1; find = 0;
    do{
        mid = (low + high)/2;
        if(key == list[mid].num){
            cout << mid << endl;
            find = 1;
        } else if(key < list[mid].num) high = mid - 1;
        else low = mid + 1;
    }while(find == 0 && low <= high);
    if(find == 0) cout << -1 << endl;
}

int main(){
    int n, key;
    cin >> n;
    for (int i = 0; i < n; i++){
        cin >> list[i].num;
    }
    cin >> key;
    binary_search(list, n, key);
}