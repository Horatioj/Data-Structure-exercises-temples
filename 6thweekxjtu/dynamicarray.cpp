#include<stdlib.h>
#include<stdio.h>

int main(){
    int n1, n2;
    int **array;
    printf("请输入第一维数组元素个数:");
    scanf("%d", &n1);
    printf("请输入第二维数组元素个数:");
    scanf("%d", &n2);
    array = (int**)malloc(n1 * sizeof(int*));
    for(int i = 0; i < n1; i++){
        array[i] = (int*)malloc(n2 * sizeof(int));
    }
    for(int i = 0; i < n1; i++){
        for(int j = 0; j < n2; j++){
            array[i][j] = i * n2 + j + 1;
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < n1; i++){
        free(array[i]);
    }
    free(array);
    return 0;
}