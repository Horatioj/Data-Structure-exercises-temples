#include<stdio.h>
#include<stdlib.h>

void display(int *array, int size){
    for(int i = 0; i < size; i++){
        printf("%d ", array[i]);
    }
    printf("\n");
}

int partition(int array[], int low, int high){
    int pivot = array[low];
    while(low < high){
        while(low < high && array[high] > pivot) high--;
        array[low] = array[high];
        while(low < high && array[low] <= pivot) low++;
        array[high] = array[low];         //������pivot��ֵŲ����λ��
    }
    array[low] = pivot;
    return low;
}

void QuickSort(int array[], int low, int high){
    if(low < high){
        int pivot = partition(array, low, high);
        QuickSort(array, low, pivot - 1);
        QuickSort(array, pivot + 1, high);
    }
}

int main(){
    int array[] = {49, 38, 65, 97, 76, 13, 27, 49, 10};
    int size = sizeof(array) / sizeof(int);

    // ��ӡ����
    printf("%d \n", size);
    QuickSort(array, 0, size - 1); //��ʼ������ʱ��λ��Ϊ0��(size-1)
    display(array, size);

    // int size      = 20;
    // int array[20] = {0};                 // �����ʼ��
    // for (int i = 0; i < 10; i++) {       // �������
    //     for (int j = 0; j < size; j++) { // �����С
    //         array[j] = rand() % 1000;    // �����������С 0~999
    //     }
    //     printf("ԭ�������飺");
    //     display(array, size);
    //     QuickSort(array, 0, size - 1);
    //     printf("��������飺");
    //     display(array, size);
    //     printf("\n");
    // }
    return 0;
}