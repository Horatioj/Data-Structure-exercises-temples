#include<iostream>
using namespace std;
int arr[100];
void Merge(int arr[], int l, int mid, int r){
	int *temp = new int[r - l + 1];  
	int indexl = l; 
	int indexr = mid + 1; 
	int i = 0; 
	while (indexl <= mid && indexr <= r){ 
		temp[i++] = arr[indexl] < arr[indexr] ? arr[indexl++] : arr[indexr++];
	}
	while (indexl <= mid){ 
		temp[i++] = arr[indexl++];
	}
	while (indexr <= r){ 
		temp[i++] = arr[indexr++];
	}
	for (int j = 0; j < i; ++j){ 
		arr[l + j] = temp[j];
	}
	delete[] temp; //销毁临时变量
}
void MergeSort(int arr[], int l, int r){
	if (l < r){
		int mid = (l + r) / 2;  
		MergeSort(arr, l, mid);  
		MergeSort(arr, mid + 1, r);  
		Merge(arr, l, mid, r); 
	}	
}


void swap(int arr[], int x, int y){
    int key = arr[x];
    arr[x] = arr[y];
    arr[y] = key;
}

void FilterDown(int arr[], int i, int n) { 
    int current = i;                    
    int child  = 2 * i + 1;           
    while (child < n) {
        if (child + 1 < n && arr[child] < arr[child + 1]) {
            child++;
        }
        if (arr[current] < arr[child]) { 
            swap(arr, current, child);   
            current = child;               
        }
        child = child * 2 + 1; 
    }
}

void HeapSort(int arr[], int n) {
    for(int i = n / 2 - 1; i >= 0; i--) FilterDown(arr, i, n);
    for (int i = n - 1; i > 0; i--) {
        swap(arr, 0, i); 
        FilterDown(arr, 0, i); 
    }
    for(int i = n-1; i >= 0; i--){
        if(i != 0) cout << arr[i] << " ";
        else cout << arr[i] << endl;
    }
}

int main()
{
    int n;
    cin >> n;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}
	MergeSort(arr, 0, n-1);
	for (int i = 0; i < n; i++){
        if(i != n-1) cout << arr[i] << " ";
        else cout << arr[n-1] << endl;
	}
    HeapSort(arr, n);
	return 0;
}