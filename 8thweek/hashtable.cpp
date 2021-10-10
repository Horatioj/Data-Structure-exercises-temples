#include<stdlib.h>
#include<stdio.h>
#include<math.h>
#define NULLKEY -1

int size = 13;
typedef struct{
  int *elem;
  int count;
}HashTable;

bool Init(HashTable *hTable){
  hTable->count = size;
  hTable->elem=(int*)malloc(size*sizeof(int));
  for(int i = 0; i < size; i++){
    hTable -> elem[i] = NULLKEY;
  }
  return true;
}

int Hash(int key){
  return key % size;
}

void linear_insert(HashTable* hTable, int key){
  int loc = Hash(key);
  while(hTable -> elem[loc] != NULLKEY){
    loc = (loc+1) % size;
  }
  hTable -> elem[loc] = key;
}

bool linear_s(HashTable hTable, int key, int* loc, int* count){
  *count = 1;
  *loc = Hash(key);
  while(hTable.elem[*loc] != key){
    *loc = (*loc+1) % size;
    *count += 1;
    if(hTable.elem[*loc] == NULLKEY || *loc == Hash(key)) return false;
  }
  return true;
}

//步长应是1，-1，2^2, -2^2 ……
int di(int i){
  int di = 1;
  if(i > 2){
    if(i%2==1){ i = ceil(i/2.0); return i * i;}
    else{i = i/2; di = -1 * i * i; return di;}
  }
  if(i == 2) return -di;
  else return di;
}

void quadra_insert(HashTable* hTable, int key){
  int loc = Hash(key);
  int temp = loc;
  int count = 0;
  while(hTable -> elem[temp] != NULLKEY){
    if(count % 2 == 0){
      temp = (loc + (int)pow((float)(1 + count / 2), 2)) % size;
    }
    else temp = (loc - (int)pow((float)(1 + count / 2), 2)) % size;
    count++;
  }
  hTable -> elem[temp] = key;
}

bool quadra_s(HashTable *hTable, int key, int &loc, int &count){
  count = 1;
  loc = Hash(key);
  int temp = loc;
  while(hTable -> elem[temp] != key){
    if(count % 2 == 0){
      temp = (loc + (int)pow((float)(1 + count / 2), 2)) % size;
      count++;
    }
    else{
      temp = (loc - (int)pow((float)(1 + count / 2), 2)) % size;
      count++;
    }
    if(hTable -> elem[temp] == NULLKEY || temp == Hash(key)) return false;
    count++;
  }
  loc = temp;
  return true;
}

int main(){
  printf("------------哈希表构造结果及三种方法的平均查找长度------------\n");
  HashTable H1;
  HashTable *H2 = new HashTable;
  Init(&H1);
  Init(H2);
  int arr[10] = {5, 88, 12, 56, 71, 28, 33, 43, 93, 17};
  int HashList[10];
  int i, j, p1, c1, p2, c2, len1, len2, len3;
  len1 = len2 = len3 = 0;

  printf("\n-----线性探测再散列-----\n");
  for(i = 0; i < 10; i++){
    linear_insert(&H1, arr[i]);
  }
  for(i = 0; i < 10; i++){
    linear_s(H1, arr[i], &p1, &c1);
    printf("%d 地址 %d 查找次数 %d\n", arr[i], p1, c1);
    len1 += c1;
  }
  printf("散列表为：\n");
  for(i = 0; i < 13; i++){
    printf("%d ", H1.elem[i]);
  }
  printf("\n线性探测平均查找长度为%.2f\n", (len1/10.0));
  

  printf("\n-----二次探测法-----\n");
  for(i = 0; i < 10; i++){
    quadra_insert(H2, arr[i]);
  }
  for(i = 0; i < 10; i++){
    quadra_s(H2, arr[i], p2, c2);
    printf("元素 %d 地址 %d 查找次数 %d \n", arr[i], p2, c2);
    len2 += c2;
  }
  printf("散列表为：\n");
  for(i = 0; i < 13; i++){
    printf("%d ", H2 -> elem[i]);
  }
  printf("\n二次探测平均查找长度为%.2f\n", (len2/10.0));
  

  printf("\n-----链地址法-----\n");
  for(i = 0; i < 10; i++){
    HashList[i] = Hash(arr[i]);
  }
  for(i = 0; i < 10; i++){
    int count = 1;
      for(j = i+1; j < 10; j++){
        if(HashList[i] == HashList[j]) count += 1;
      }
      len3 += count;
  }
  for(i = 0; i < 10; i++){
    printf("元素 %d 地址 %d \n", arr[i], HashList[i]);
  }
  //printf("散列表为：\n");
  printf("\n链地址法平均查找长度为%.2f\n", (len3/10.0));
}