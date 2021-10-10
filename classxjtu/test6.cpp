#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MaxSemester 12
#define MaxCourse 100

//弧结点
typedef struct ArcNode{
	int AdjVex;
	ArcNode* Next;
}ArcNode;

//顶点结点
typedef struct VexNode{
	char Date[4];
	int Credit;
	ArcNode* FirstArc;
}VexNode;

//学期信息
typedef struct Info{
	int SemesterNum;
	int MaxCredit;
}Info;

//图
typedef struct Graph{
	int VexNum;
	int ArcNum;
	int* InDegree;
	VexNode* Vertex;
	Info* ExtraInfo;
}Graph;

//栈辅助拓扑排序(pos便于后续输出课程)
typedef struct Stack{
	int* Vertex;
	int bottom, pos;
}Stack;

//初始化辅助栈
void InitStack(Stack* S) {
	S -> Vertex = (int*)malloc(MaxCourse * sizeof(int));
	S -> pos = S -> bottom = 0;
}

int Transfer(char *ch){
    if(ch[1] == '0') return ch[2] - '1';
    else return (ch[1] - '0') * 10 + ch[2] - '1';
}

//从文件读取信息
void Creat_Graph1(Graph* G) {

	//初始化指针
	G -> ExtraInfo = (Info*)malloc(sizeof(Info));

	//从文件读取信息
	FILE* fp = fopen("course_info.txt", "r");
	if (NULL == fp) {
		printf("文件路径有误");
		exit(EXIT_FAILURE);
	}

	//读学期总数 学分上限 课程总数(顶点数量)
	fscanf(fp, "%d%d%d", &G ->ExtraInfo -> SemesterNum, &G ->ExtraInfo -> MaxCredit, &G -> VexNum);
	G -> ArcNum = 0;

	if (G -> VexNum > MaxCourse) {
		printf("超出最大课程数%d,请更改数据\n", MaxCourse);
		exit(EXIT_FAILURE);
	}
	if (G ->ExtraInfo -> SemesterNum > 12) {
		printf("超出最大学期数%d,请更改数据\n", MaxSemester);
		exit(EXIT_FAILURE);
	}
	G -> Vertex = (VexNode*)malloc(sizeof(VexNode) * G -> VexNum);

	for (int i = 0; i < G -> VexNum; i++){
		G -> Vertex[i].FirstArc = NULL;
	}
	//读取课程信息
	for (int i = 0; i < G -> VexNum; i++) {

		//读取课程名称和学分
		fscanf(fp, "%s%d", G -> Vertex[i].Date, &G -> Vertex[i].Credit);

		//根据前序课程建立弧节点
		while ('\n' != fgetc(fp)) {
			char str[4];
			int pos;

			fscanf(fp, "%s", str);
			pos = Transfer(str);

			//判断课程是不是没有
			if (pos < 0 || pos > G -> VexNum) {
				printf("%s请输入正确的先决条件！\n", G -> Vertex[i].Date);
				exit(EXIT_FAILURE);
			}

			//更新弧节点 注意是pos指向i的弧
			ArcNode* p = (ArcNode*)malloc(sizeof(ArcNode));
			p -> AdjVex = i;
			p -> Next = G -> Vertex[pos].FirstArc;
			G -> Vertex[pos].FirstArc = p;
			G -> ArcNum++;
		}
	}
	fclose(fp);

	//更新入度数组
	G -> InDegree = (int*)malloc(sizeof(int) * G -> VexNum);
	memset(G -> InDegree, 0, sizeof(int) * G -> VexNum);

	for (int i = 0; i < G -> VexNum; i++) {
		for (ArcNode* p = G -> Vertex[i].FirstArc; NULL != p; p = p -> Next) {
			G -> InDegree[p -> AdjVex]++;
		}
	}
}

//键盘键入
void Create_Graph2(Graph *g){
	
}

//均匀分布
void Method1(Graph G, Stack S) {
	int TotalCredit = 0;
	for (int i = 0; i < G.VexNum; i++)
		TotalCredit += G.Vertex[i].Credit;
	int EachSemCredit = TotalCredit / G.ExtraInfo -> SemesterNum;
	FILE* fp = fopen("result.txt", "w");
	for (int i = 0; i < G.ExtraInfo -> SemesterNum; i++) {
		int tmp = 0;
		printf("\n第%d个学期的课程：", i + 1);
		fprintf(fp, "\n第%d个学期的课程：", i + 1);
		do {
			printf("%s ", G.Vertex[S.Vertex[S.pos]].Date);
			fprintf(fp, "%s ", G.Vertex[S.Vertex[S.pos]].Date);
			tmp += G.Vertex[S.Vertex[S.pos++]].Credit;
		} while(tmp < EachSemCredit && S.pos < G.VexNum);
	}
	fclose(fp);
}

//集中在前几个学期
void Method2(Graph G) {
	FILE* fp = fopen("结果.txt", "w");

	//重新更新入度数组
	memset(G.InDegree, 0, sizeof(int) * G.VexNum);
	for (int i = 0; i < G.VexNum; i++) {
		for(ArcNode* p = G.Vertex[i].FirstArc; NULL != p; p = p -> Next) {
			G.InDegree[p -> AdjVex]++;
		}
	}
	int count = 0;

	//记忆哪些课程是上学期学的
	int* Mark = (int*)malloc(sizeof(int) * G.VexNum);

	//外层循环为学期数
	for (int i = 0; i < G.ExtraInfo -> SemesterNum; i++) {
		printf("\n第%d个学期的课程：", i + 1);
		fprintf(fp, "\n第%d个学期的课程：", i + 1);
		memset(Mark, 0, sizeof(int) * G.VexNum);

		//扫描一遍入度结点把所有为0的输出
		for (int j = 0; j < G.VexNum; j++) {
			if (0 == G.InDegree[j]) {
				count++;
				Mark[j] = 1;
				G.InDegree[j]--;
				printf("%s ", G.Vertex[j].Date);
				fprintf(fp, "%s ", G.Vertex[j].Date);
			}
		}
		if (G.VexNum == count) break;
		//扫描Mark数组 通过标记为1的位置来更新入度结点
		for (int j = 0; j < G.VexNum; j++) {
			if (Mark[j]) {
				for (ArcNode* p = G.Vertex[j].FirstArc; NULL != p; p = p -> Next) G.InDegree[p -> AdjVex]--;
			}
		}
	}
	fclose(fp);
}

void TopologicalSort(Graph G) {
	Stack S, OutCome;
	InitStack(&S);
	InitStack(&OutCome);

	//寻找入读为0的顶点入栈
	for (int i = 0; i < G.VexNum; i++) {
		if (!G.InDegree[i]) {
			S.Vertex[S.bottom++] = i;
		}
	}

	while (0 < S.bottom) {
		int tmp = OutCome.Vertex[OutCome.bottom++] = S.Vertex[--S.bottom];
		for (ArcNode* p = G.Vertex[tmp].FirstArc; NULL != p; p = p -> Next) {
			G.InDegree[p -> AdjVex]--;
			if (0 == G.InDegree[p -> AdjVex])
				S.Vertex[S.bottom++] = p -> AdjVex;
		}
	}

	if (OutCome.bottom != G.VexNum) {
		printf("课程的先决条件有误！\n");
		exit(EXIT_FAILURE);
	}
	printf("请输入分配课程要求:均匀式(1)集中式(2)");

	int Command;
	scanf("%d", &Command);

	switch (Command) {
		case 1: Method1(G, OutCome); break;
		case 2: Method2(G); break;
		default: {
			printf("命令错误！");
			exit(EXIT_FAILURE);
		}
	}
}

//修改，键盘键入

int main(void) {
	Graph G;
	Creat_Graph1(&G);
	TopologicalSort(G);
	return 0;
}
