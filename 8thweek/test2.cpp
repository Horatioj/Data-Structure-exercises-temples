#include<stdio.h>
#include<stdlib.h>

int main(){

    
    int arr[10] = {5, 88, 12, 56, 71, 28, 33, 43, 93, 17};
    int H[10];
    int len1 = 0;
    for(int i = 0; i < 10; i++){
        H[i] = arr[i] % 13;
    }
    for(int i = 0; i < 10; i++){
        printf("Hashֵ值为%d\n", H[i]);
    }
    for(int i = 0; i < 10; i++){
        int count = 1;
        for(int j = i+1; j < 10; j++){
            if(H[i] == H[j]) count += 1;
        }
        len1 += count;
    }
    printf("%.2f", (len1/10.0));
}