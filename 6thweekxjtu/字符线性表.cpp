/*创建一个字符线性表（顺序表），并实现其基本操作（如插入，查找，删除，输出等）。
应用该线性表，将键盘输入的一行字符插入表中，然后输出表中所有字符及表长；
再输入一个字符，从表中删除该字符（重复出现应进行多次删除），最后再次输出表中所有字符及表长。
输入样例：
ABCBBDEF 12XYZBA
输出样例：
ABCBBDEF 12XYZBA
16
再输入：
B
则输出为：
ACDEF 12XYZA
12
*/

/* 第六周编程题:
#include<stdio.h>
#include<string.h>

int main() {
	char arr1[100], arr2[100];
	gets(arr1);
   int len = strlen(arr1);
	char m,j=0;
	scanf("%c", &m);
	for (int i = 0; i < len; i++)
	{
		if (arr1[i]!=m)
		{
			arr2[j] = arr1[i];
			j++;
		}
	}
	arr2[j] = '\0';
	printf("%s\n%d\n", arr1, len);
	printf("%s\n%d", arr2, j);
	return 0;
}
*/

#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<windows.h>

#define TRUE            1
#define FALSE           0
#define OK              1
#define ERROR           0
#define INFEASIBLE      -1
#define OVERFLOW        -2
#define LIST_INIT_SIZE  100
#define LISTINCREMENT   10

typedef int Status;
typedef int ElemType;

typedef struct{
    ElemType *elem;
    int length;
    int listsize;
}SqList;

Status InitList_Sq(SqList &L){
    L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(L.elem == NULL) {          //!L.elem 
        printf("存储空间分配失败\n");
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    printf("成功创建一个空的线性表\n");
    return OK;
}

//对线性表进行赋值
Status ValueList_Sq(SqList &L){
    int i, j;
    printf("请输入线性表元素个数: ");
    scanf("%d", &i);
    while(i > L.listsize){
        L.elem = (ElemType *)realloc(L.elem, LIST_INIT_SIZE * sizeof(ElemType));
        L.listsize += LISTINCREMENT;
    }
    for(j = 0; j < i; j++){
        printf("请输入第%d个元素: ", j + 1);
        scanf("%d", &L.elem[j]);
    }
    L.length = i;
    printf("赋值成功\n");
    return OK;
}

//销毁线性表
Status DestroyList_Sq(SqList &L){
    if(!L.elem){ //L.elem == NULL
        printf("无线性表存在");
        return ERROR;
    }
    free(L.elem);
    L.elem = NULL;
    L.length = 0;
    L.listsize = 0;
    printf("线性表已销毁\n");
    return OK;
}

//重置线性表
Status ClearList_Sq(SqList &L){
    if(L.elem){
        L.length = 0;
        printf("线性表已重置\n");
        return OK;
    }else 
        printf("线性表不存在"); 
        return OK;
}

//判断线性表是否为空
Status IsEmpty_Sq(SqList L){
    if(L.elem){
        if(L.length != 0){
            printf("线性表不为空");
            return FALSE;
        }else printf("线性表是空表\n");
        return TRUE;
    }
    else printf("线性表不存在\n");
    return OK;
}

//获取线性表的长度
Status ListLength_Sq(SqList L){
    if(L.elem){
        int K = L.length;
        printf("线性表的长度: ", K);
        return OK;
    }
    else printf("线性表不存在\n");
    return OK;
}

//获取线性表某一元素位置
Status GetElem_Sq(SqList L, int index){
    int num;
    if(index <= 0 || index > L.length){
        printf("请输入一个有效数字!\n");
        return ERROR;
    }else{
        num = L.elem[index-1];
        printf("第%d个位置的元素为：%d", index, num);
        return OK;
    }
}

//插入元素
Status ListInsert_Sq(SqList &L, int i, ElemType e){
    ElemType *newbase;
    int *q, *p;
    if(i < 1 || i >= L.length + 1) return ERROR;
    if(L.length >= L.listsize){
        newbase = (ElemType *)realloc(L.elem, (L.listsize + LISTINCREMENT)*sizeof(ElemType));
        if(!newbase){
            printf("存储空间分配失败\n");
            exit(OVERFLOW);
        }
    }
    q = &(L.elem[i-1]);
    for(p = &(L.elem[L.length - 1]); p >= q; --p){
        *(p + 1) = *p;
    }
    *q = e;
    ++L.length;
    printf("元素插入成功\n");
    return OK;
}

//删除元素
Status DeleteList_Sq(SqList &L, int i){
    int *p, *q;
    if(i < 1 || i > L.length){
        printf("请输入一个有效数字\n");
        return ERROR;
    }
    p = &(L.elem[i - 1]);
    q = L.elem + L.length - 1;
    for(++p; p <=  q;p++){
        *(p - 1) = *p;
    }
    --L.length;
    printf("第%d个元素删除成功!\n", i);
    return OK;
}

//寻找前驱
Status PriorElem_Sq(SqList L, int i){
    int K;
    if(L.elem){
        if(i <= 1 || i > L.length + 1){
            printf("请输入一个有效数字\n");
        }
        K = L.elem[i - 1];
        printf("第%d个位置的直接前驱为：%d\n", i, K);
    }
    else printf("线性表不存在\n");
    return OK;
}

//寻找后继
Status NextElem_Sq(SqList L, int i){
    int K;
    if(L.elem){
        if(i <= 1 || i > L.length - 1) printf("请输入一个有效数字\n");
        K = L.elem[i];
        printf("第%d个位置的直接后继为：%d\n", i, K);
    }
    else printf("线性表不存在\n");
    return OK;
}

//打印线性表
Status PrintList_Sq(SqList L){
    printf("当前线性表的元素为：");
    for(int K = 0; K < L.length; K++){
        printf(" %d", L.elem[K]);
    }
    printf("\n");
    return OK;
}

int main(){
    SetConsoleTitle("线性表测试");
    SqList L;
    int choose, index, e;
    while(1){
		printf("*****************************************\n");
		printf("*                                       *\n");
		printf("*  线性表的顺序表示和实现：             *\n");
		printf("*                                       *\n");
		printf("*    1.  构造一个空的线性表             *\n");
		printf("*    2.  对线性表进行赋值               *\n");
		printf("*    3.  对线性表进行销毁               *\n");
		printf("*    4.  对线性表进行重置               *\n"); 
		printf("*    5.  判断线性表是否为空             *\n");
		printf("*    6.  获取线性表的长度               *\n");
		printf("*    7.  获取线性表某一位置对应的元素   *\n");
		printf("*    8.  在线性表某一位置插入元素       *\n");
		printf("*    9.  删除线性表某一位置的元素       *\n");
		printf("*    10. 求线性表某一元素的前驱         *\n");
		printf("*    11. 求线性表某一元素的后继         *\n");
		printf("*    12. 打印线性表                     *\n");
		printf("*    13. 退出                           *\n");
		printf("*                                       *\n");
		printf("*****************************************\n");
		printf("请做出您的选择：");
		scanf("%d", &choose);
		switch(choose){
			case 1:InitList_Sq(L); break;
			case 2:ValueList_Sq(L); break;
			case 3:DestroyList_Sq(L); break;
			case 4:ClearList_Sq(L); break;
			case 5:IsEmpty_Sq(L); break;
			case 6:ListLength_Sq(L); break;
			case 7:{
				printf("请输入要获取元素的位置：");
				scanf("%d", &index);
				GetElem_Sq(L, index);
			}
			break;
			case 8:{
				printf("请输入要插入元素的位置：");
				scanf("%d", &index);
				printf("请输入要插入的元素：");
				scanf("%d", &e);
				ListInsert_Sq(L, index,e);
			}
			break;
			case 9:{
				printf("请输入要删除元素的位置：");
				scanf("%d", &index);
				DeleteList_Sq(L, index);	
			}
			break;
			case 10:{
				printf("请输入想要查找哪一个元素的前驱：");
				scanf("%d", &index);
				PriorElem_Sq(L, index);
			}
			break;
			case 11:{
				printf("请输入想要查找哪一个元素的后继：");
				scanf("%d", &index);
				NextElem_Sq(L, index);
			}
			break; 
			case 12:PrintList_Sq(L); break;
			case 13:exit(0);
		}
	}
	return 0;
}