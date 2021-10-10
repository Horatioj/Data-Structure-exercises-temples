/*
Project: ͼ-���·��-Bellman-Ford�㷨���ɺ��и�Ȩ����
Date:    2019/10/24
Author:  Frank Yu
������������:
InitGraph(Graph &G)             ��ʼ������ ������ͼG ���ã���ʼ��ͼ�Ķ�����ڽӾ����
InsertNode(Graph &G,VexType v) ����㺯�� ������ͼG,����v ���ã���ͼG�в��붥��v,���ı䶥���
InsertEdge(Graph &G,VexType v,VexType w) ���뻡���� ������ͼG,ĳ�����˵�v��w ���ã���ͼG����v,w֮����뻡�����ı��ڽӾ���
Adjancent(Graph G,VexType v,VexType w) �ж��Ƿ���ڻ�(v,w)���� ������ͼG��ĳ�����˵�v��w ���ã��ж��Ƿ���ڻ�(v,w)
BFS(Graph G, int start) ��ȱ������� ������ͼG,��ʼ����±�start ���ã���ȱ���
DFS(Graph G, int start) ��ȱ����������ݹ���ʽ��������ͼG,��ʼ����±�start ���ã���ȱ���
Dijkstra(Graph G, int v)  ���·�� - Dijkstra�㷨 ������ͼG��Դ��v
Bellman_Ford(Graph G, int v)  ���·�� - Bellman_Ford�㷨  ������ͼG��Դ��v ���ã����㲻����Ȧͼ�����·�� �����Ƿ���Ȧ
Floyd_Wallshall(Graph G)    ���·�� - Floyd_Wallshall�㷨  ������ͼG ���ã����㲻����Ȧͼ�����·�� �����Ƿ���Ȧ
����ʵ�ֺ�����
CreateGraph(Graph &G) ����ͼ����ʵ�ֺ��� ������ͼG  InsertNode ���ã�����ͼ
BFSTraverse(Graph G)  ��ȱ�������ʵ�ֺ��� ������ͼG ���ã���ȱ���
DFSTraverse(Graph G)  ��ȱ�������ʵ�ֺ��� ������ͼG ���ã���ȱ���
Shortest_Dijkstra(Graph &G) �������·��-Dijkstra�㷨 ������ͼG��Դ��v
Shortest_Bellman_Ford(Graph &G) �������·��- - Bellman_Ford�㷨  ������ͼG
Shortest_Floyd_Wallshall(Graph &G) �������·��- - Floyd_Wallshall�㷨  ������ͼG
*/
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<string>
#include<set>
#include<list>
#include<queue>
#include<vector>
#include<map>
#include<iterator>
#include<algorithm>
#include<iostream>
#define MaxVerNum 100 //���������Ŀֵ
#define VexType char //������������
#define EdgeType int //����������,����ͼʱ�ڽӾ��󲻶Գƣ���Ȩֵʱ��ʾȨֵ��û��ʱ1��0����
#define INF 0x3f3f3f3f//��Ϊ���ֵ
using namespace std;
//ͼ�����ݽṹ
typedef struct Graph
{
	VexType Vex[MaxVerNum];//�����
	EdgeType Edge[MaxVerNum][MaxVerNum];//����
	int vexnum, arcnum;//������������
}Graph;
//�Ͻ�˹�����㷨ȫ�ֱ���
bool S[MaxVerNum]; //���㼯
int D[MaxVerNum];  //��������������·��
int F_D[MaxVerNum][MaxVerNum];//Floyd��D���� ��¼���·��
int Pr[MaxVerNum]; //��¼ǰ��
//*********************************************������������*****************************************//
//��ʼ������ ������ͼG ���ã���ʼ��ͼ�Ķ�����ڽӾ����
int P[MaxVerNum][MaxVerNum];//���·����¼����
void InitGraph(Graph &G)
{
	memset(G.Vex, '#', sizeof(G.Vex));//��ʼ�������
									  //��ʼ������
	for (int i = 0; i < MaxVerNum; i++)
		for (int j = 0; j < MaxVerNum; j++)
			G.Edge[i][j] = INF;
	G.arcnum = G.vexnum = 0;          //��ʼ��������������
}
//����㺯�� ������ͼG,����v ���ã���ͼG�в��붥��v,���ı䶥���
bool InsertNode(Graph &G, VexType v)
{
	if (G.vexnum < MaxVerNum)
	{
		G.Vex[G.vexnum++] = v;
		return true;
	}
	return false;
}
//���뻡���� ������ͼG,ĳ�����˵�v��w ���ã���ͼG����v,w֮����뻡�����ı��ڽӾ���
bool InsertEdge(Graph &G, VexType v, VexType w, int weight)
{
	int p1, p2;//v,w�����±�
	p1 = p2 = -1;//��ʼ��
	for (int i = 0; i<G.vexnum; i++)//Ѱ�Ҷ����±�
	{
		if (G.Vex[i] == v)p1 = i;
		if (G.Vex[i] == w)p2 = i;
	}
	if (-1 != p1&&-1 != p2)//���������ͼ���ҵ�
	{
		G.Edge[p1][p2] = weight;//����ͼ�ڽӾ��󲻶Գ�
		G.arcnum++;
		return true;
	}
	return false;
}
//�ж��Ƿ���ڻ�(v,w)���� ������ͼG��ĳ�����˵�v��w ���ã��ж��Ƿ���ڻ�(v,w) 
bool Adjancent(Graph G, VexType v, VexType w)
{
	int p1, p2;//v,w�����±�
	p1 = p2 = -1;//��ʼ��
	for (int i = 0; i<G.vexnum; i++)//Ѱ�Ҷ����±�
	{
		if (G.Vex[i] == v)p1 = i;
		if (G.Vex[i] == w)p2 = i;
	}
	if (-1 != p1&&-1 != p2)//���������ͼ���ҵ�
	{
		if (G.Edge[p1][p2] == 1)//���ڻ�
		{
			return true;
		}
		return false;
	}
	return false;
}
bool visited[MaxVerNum];//���ʱ�����飬���ڱ���ʱ�ı��
//��ȱ������� ������ͼG,��ʼ����±�start ���ã���ȱ���
void BFS(Graph G, int start)
{
	queue<int> Q;//��������
	cout << G.Vex[start];//���ʽ��
	visited[start] = true;
	Q.push(start);//���
	while (!Q.empty())//���зǿ�
	{
		int v = Q.front();//�õ���ͷԪ��
		Q.pop();//����
		for (int j = 0; j<G.vexnum; j++)//�ڽӵ�
		{
			if (G.Edge[v][j] < INF && !visited[j])//���ڽӵ���δ����
			{
				cout << "->";
				cout << G.Vex[j];//���ʽ��
				visited[j] = true;
				Q.push(j);//���
			}
		}
	}//while
	cout << endl;
}
//��ȱ����������ݹ���ʽ��������ͼG,��ʼ����±�start ���ã���ȱ���
void DFS(Graph G, int start)
{
	cout << G.Vex[start];//����
	visited[start] = true;
	for (int j = 0; j < G.vexnum; j++)
	{
		if (G.Edge[start][j] <INF && !visited[j])//���ڽӵ���δ����
		{
			cout << "->";
			DFS(G, j);//�ݹ���ȱ���
		}
	}
}
//���·�� - Dijkstra�㷨 ������ͼG��Դ��v3
void Dijkstra(Graph G, int v)
{
	//��ʼ��
	int n = G.vexnum;//nΪͼ�Ķ������
	for (int i = 0; i < n; i++)
	{
		S[i] = false;
		D[i] = G.Edge[v][i];
		if (D[i] < INF)Pr[i] = v; //v��i���ӣ�vΪǰ��
		else Pr[i] = -1;
	}
	S[v] = true;
	D[v] = 0;
	//��ʼ������,�����·����������S��
	for (int i = 1; i < n; i++)
	{
		int min = INF;
		int temp;
		for (int w = 0; w < n; w++)
			if (!S[w] && D[w] < min) //ĳ��tempδ����s������Ϊ��ǰ���·��
			{
				temp = w;
				min = D[w];
			}
		S[temp] = true;
		//���´�Դ����������������·�� ͨ��temp
		for (int w = 0; w < n; w++)
			if (!S[w] && D[temp] + G.Edge[temp][w] < D[w])
			{
				D[w] = D[temp] + G.Edge[temp][w];
				Pr[w] = temp;
			}
	}
}
//���·�� - Bellman_Ford�㷨  ������ͼG��Դ��v ���ã����㲻����Ȧͼ�����·�� �����Ƿ���Ȧ
bool Bellman_Ford(Graph G, int v)
{
	//��ʼ��
	int n = G.vexnum;//nΪͼ�Ķ������
	for (int i = 0; i < n; i++)
	{
		D[i] = G.Edge[v][i];
		if (D[i] < INF)Pr[i] = v; //v��i���ӣ�vΪǰ��
		else Pr[i] = -1;
	}
	D[v] = 0;
	//��ʼ����������ʼ˫��ѭ��
	for (int i = 2; i<G.vexnum - 1; i++)
		for (int j = 0; j<G.vexnum; j++) //jΪԴ��
			for (int k = 0; k<G.vexnum; k++) //kΪ�յ�
				if (D[k] > D[j] + G.Edge[j][k])
				{
					D[k] = D[j] + G.Edge[j][k];
					Pr[k] = j;
				}
	//�ж��Ƿ��и�Ȧ
	bool flag = true;
	for (int j = 0; j<G.vexnum - 1; j++) //jΪԴ��
		for (int k = 0; k<G.vexnum - 1; k++) //kΪ�յ�
			if (D[k] > D[j] + G.Edge[j][k])
			{
				flag = false;
				break;
			}
	return flag;
}
//���·�� - Floyd_Wallshall�㷨  ������ͼG ���ã����㲻����Ȧͼ�����·�� �����Ƿ���Ȧ
bool Floyd_Wallshall(Graph G)
{
	//��ʼ��
	for (int i = 0; i<G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
		{
			if (i == j)F_D[i][j] = 0;
			else F_D[i][j] = G.Edge[i][j];
			P[i][j] = -1;
		}
	//��ʼ����������ʼ����
	for(int k=0;k<G.vexnum;k++)
		for (int i = 0; i<G.vexnum; i++)
			for (int j = 0; j<G.vexnum; j++)
				if (F_D[i][j] > F_D[i][k] + F_D[k][j])
				{
					F_D[i][j] = F_D[i][k] + F_D[k][j];
					P[i][j] = k;
				}
	bool flag = true;
	for (int i = 0; i < G.vexnum; i++)
		for (int j = 0; j < G.vexnum; j++)
			if (i==j&&F_D[i][j] < 0)
			{
				flag = false;
				break;
			}
	return flag;
}
//������·��
void Path(Graph G, int v)
{
	if (Pr[v] == -1)
		return;
	Path(G, Pr[v]);
	cout << G.Vex[Pr[v]] << "->";
}
// ���Floyd���·�� v���յ�
void F_Path(Graph G, int v, int w)
{
	cout << "->"<< G.Vex[P[v][w]] ;
	if (P[v][w] == -1)
		return;
	F_Path(G, v,P[v][w]);
	
}
//**********************************************����ʵ�ֺ���*****************************************//
//��ӡͼ�Ķ����
void PrintVex(Graph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		cout << G.Vex[i] << " ";
	}
	cout << endl;
}
//��ӡͼ�Ļ�����
void PrintEdge(Graph G)
{
	for (int i = 0; i < G.vexnum; i++)
	{
		for (int j = 0; j < G.vexnum; j++)
		{
			if (G.Edge[i][j] == INF)cout << "�� ";
			else cout << G.Edge[i][j] << " ";
		}
		cout << endl;
	}
}
//����ͼ����ʵ�ֺ��� ������ͼG  InsertNode ���ã�����ͼ
void CreateGraph(Graph &G)
{
	VexType v, w;
	int vn, an;//������������
	cout << "�����붥����Ŀ:" << endl;
	cin >> vn;
	cout << "�����뻡��Ŀ:" << endl;
	cin >> an;
	cout << "���������ж�������:" << endl;
	for (int i = 0; i<vn; i++)
	{
		cin >> v;
		if (InsertNode(G, v)) continue;//�����
		else {
			cout << "�������" << endl; break;
		}
	}
	cout << "���������л���ÿ��������㣬�յ㼰Ȩֵ��:" << endl;
	for (int j = 0; j<an; j++)
	{
		int weight;
		cin >> v >> w >> weight;
		if (InsertEdge(G, v, w, weight)) continue;//���뻡
		else {
			cout << "�������" << endl; break;
		}
	}
	cout << "ͼ�Ķ��㼰�ڽӾ���" << endl;
	PrintVex(G);
	PrintEdge(G);
}
//��ȱ�������ʵ�ֺ��� ������ͼG ���ã���ȱ���
void BFSTraverse(Graph G)
{
	for (int i = 0; i<MaxVerNum; i++)//��ʼ�����ʱ������
	{
		visited[i] = false;
	}
	for (int i = 0; i < G.vexnum; i++)//��ÿ����ͨ�������б���
	{
		if (!visited[i])BFS(G, i);
	}
}
//��ȱ�������ʵ�ֺ��� ������ͼG ���ã���ȱ���
void DFSTraverse(Graph G)
{
	for (int i = 0; i<MaxVerNum; i++)//��ʼ�����ʱ������
	{
		visited[i] = false;
	}
	for (int i = 0; i < G.vexnum; i++)//��ÿ����ͨ�������б���
	{
		if (!visited[i])
		{
			DFS(G, i); cout << endl;
		}
	}
}
//�������·��-Dijkstra�㷨 ������ͼG
void Shortest_Dijkstra(Graph &G)
{
	char vname;
	int v = -1;
	cout << "������Դ������:" << endl;
	cin >> vname;
	for (int i = 0; i < G.vexnum; i++)
		if (G.Vex[i] == vname)v = i;
	if (v == -1)
	{
		cout << "û���ҵ�����㣡" << endl;
		return;
	}
	Dijkstra(G, v);
	cout << "Ŀ���" << "\t" << "���·��ֵ" << "\t" << "���·��" << endl;
	for (int i = 0; i < G.vexnum; i++)
	{
		if (i != v)
		{
			cout << "  " << G.Vex[i] << "\t" << "        " << D[i] << "\t";
			Path(G, i);
			cout << G.Vex[i] << endl;
		}
	}
}
//�������·��- - Bellman_Ford�㷨  ������ͼG
void Shortest_Bellman_Ford(Graph &G)
{
	char vname;
	int v = -1;
	cout << "������Դ������:" << endl;
	cin >> vname;
	for (int i = 0; i < G.vexnum; i++)
		if (G.Vex[i] == vname)v = i;
	if (v == -1)
	{
		cout << "û���ҵ�����㣡" << endl;
		return;
	}
	if (Bellman_Ford(G, v))
	{
		cout << "Ŀ���" << "\t" << "���·��ֵ" << "\t" << "���·��" << endl;
		for (int i = 0; i < G.vexnum; i++){
			cout << "  " << G.Vex[i] << "\t" << "        " << D[i] << "\t";
			Path(G, i);
			cout << G.Vex[i] << endl;
		}
	}
	else
	{
		cout << "�����ͼ�к��и�Ȧ������ʹ�ø��㷨��" << endl;
	}
}
//�������·��- - Floyd_Wallshall�㷨  ������ͼG
void Shortest_Floyd_Wallshall(Graph &G)
{
	if (Floyd_Wallshall(G))
	{
		cout << "���·��ֵ" << "\t" << "���·��" << endl;
		for (int i = 0; i < G.vexnum; i++)
			for (int j = 0; j < G.vexnum; j++){
			cout << "     "<<F_D[i][j] << "   \t";
			cout << G.Vex[i];
			F_Path(G, i,j);
			cout << G.Vex[j] << endl;
		}
	}
	else
	{
		cout << "�����ͼ�к��и�Ȧ������ʹ�ø��㷨��" << endl;
	}
}
//�˵�
void menu()
{
	cout << "************1.����ͼ       2.��ȱ���******************" << endl;
	cout << "************3.��ȱ���     4.�Ͻ�˹����****************" << endl;
	cout << "************5.����������   6.��������******************" << endl;
	cout << "************7.�˳�*************************************" << endl;
}
//������
int main()
{
	int choice = 0;
	Graph G;
	InitGraph(G);
	while (1)
	{
		menu();
		printf("������˵���ţ�\n");
		scanf("%d", &choice);
		if (7 == choice) break;
		switch (choice)
		{
		case 1:CreateGraph(G); break;
		case 2:BFSTraverse(G); break;
		case 3:DFSTraverse(G); break;
		case 4:Shortest_Dijkstra(G); break;
		case 5:Shortest_Bellman_Ford(G); break;
		case 6:Shortest_Floyd_Wallshall(G); break;
		default:printf("������󣡣���\n"); break;
		}
	}
	return 0;
}