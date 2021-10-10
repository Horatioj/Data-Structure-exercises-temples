#include<iostream>
#include<cstdio>
#include<cstring>
#include<fstream>
#include<stack>

using namespace std;
#define MAX_COURSE 100
#define MAX_SEMESTER 12

typedef struct Course{  //课程即图上结点
    char id[4];
    char name[30];
    int credit;
    bool cexist;
    ArcNode *FirstEdge;
    //int InDegree;
}Course;

typedef struct Graph{
    int VexNum;
    int EdgeNum;
    int *InDegree;
    Course *Vex;
    Info *ExtraInfo;
}Graph;

typedef struct ArcNode{  //弧结点
    int AdjVex;
    ArcNode *next;
}ArcNode;

typedef struct Info{
    int SemNum;         //学期数目
    int CreNum;         //学分数量
}Info;

typedef struct Stack{
    int *Vex;
    int curr, bottom;
}Stack;

int Transfer(char *ch){
    if(ch[1] == '0') return ch[2] - '1';
    else return (ch[1] - '0') * 10 + ch[2] - '1';
}

void InitS(Stack *S){
    S -> Vertex = (int*)malloc(MAX_COURSE * sizeof(int));
	S -> pos = S -> bottom = 0;
}


void Create(Graph *g){
    int flag = 0;
    cout << "请选择数据读取方式：文件读取(0);键入数据(1)";
    cin >> flag;
    G -> Info = (Info*)malloc(sizeof(Info));
    if(flag == 0){
        fstream file;
        file.open("Course.txt", ios::in | ios::binary);
        if(!file){
            cout << "文件不存在！" << endl;
            abort();
        }
    }
    else if(flag == 1){

    }
    else cout << "请选择正确的输入方式！" << endl;
}