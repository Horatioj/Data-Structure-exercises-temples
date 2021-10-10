#include <iostream>
#include <cstdlib>
#include <math.h>
#define HASHSIZE 13/*散列表的大小*/
#define NULLKEY -1/*空白标志*/

using namespace std;
typedef struct
{
	int *elem;
	int count;
}HashTable;

int m = 13; 

bool InitHashTable(HashTable *H)/*初始化*/
{
	H->elem = (int*)malloc(HASHSIZE * sizeof(int));
	for (int i = 0; i < HASHSIZE; i++) H->elem[i] = NULLKEY;
	return true;
}

int Hash(int key)/*哈希函数f(key)=key mod m,这里mod取12*/
{
	return key % m;
}

int di(int i){
  int di = 1;
  if(i > 2){
    if(i%2==1){ i = ceil(i/2.0); return i * i;}
    else{i = i/2; di = -1 * i * i; return di;}
  }
  if(i == 2) return -di;
  else return di;
}

void InsertHash(HashTable *H, int key)/*开放定址法*/
{
	int count = 0;/*记录冲突次数，以便调整左右探测方向，冲突次数为偶数时向右探测，为奇数时向左探测*/
	int addr = Hash(key);/*计算哈希值*/
	int temp = addr;
	while (H->elem[temp] != NULLKEY)
	{
        temp = (int)(addr + di) % m;
        /*
		if(count%2==0)
		    temp = (addr + (int)pow((1 + count / 2), 2)) % m;
		else
			temp = (addr - (int)pow((1 + count / 2), 2)) % m;
        */
		count++;
	}
	H->elem[temp] = key;
}

bool SearchHash(HashTable *H, int key, int &addr, int &count)
{
	count = 1;
	addr = Hash(key);
	int temp = addr;
	while (H->elem[temp] != key)
	{
        temp = (int)(addr + di) % m;
        /*
		if (count % 2 == 0)
			{temp = (addr + (int)pow((1 + count / 2), 2)) % m; count += 1;}
		else
			{temp = (addr - (int)pow((1 + count / 2), 2)) % m; count += 1;}*/
		if (H->elem[temp] == NULLKEY || temp == Hash(key)) return false;
        count += 1;
	}
	addr = temp;
	return true;
}

int main()
{
	HashTable *test=new HashTable;
	InitHashTable(test);

	int a[10] = {5, 88, 12, 56, 71, 28, 33, 43, 93, 17};
	for (int i = 0; i < 10;i++) InsertHash(test,a[i]);

	int addr, count;
    int len = 0;
    for(int i = 0; i < 10; i++){
        SearchHash(test, a[i], addr, count);
	    printf("元素 %d 的地址 %d 查找次数 %d \n", a[i], addr, count);
        len += count;
    }
	

	cout << "散列表：" << endl;
	for (int i = 0; i < 13; i++) cout << test->elem[i]<<" ";
}
