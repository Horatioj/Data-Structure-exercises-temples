#include <stack>
#include <cstring>
#include <fstream>
#include <iostream>
#define COURSE_MAX_NUMBER 100                                         //最大课程个数
using namespace std;

//课程结构体
typedef struct Course
{
	char id[10];                                                     //课程编号
	char name[20];                                                   //课程名
	int credit;                                                      //课程学分
	bool course_exist;                                               //判断当前课程是否存在
};

//图类
class Graph
{
public:
	void Create1(Graph* p);                                     //文件形式输入课程信息创建图
	void Create2(Graph* p);                                     //键盘形式输入课程信息创建图
	void Modify(Graph* p);                                    //修改课程
	void Topology_sort(Graph* p, int toplogicalSort_reslut[]);      //拓扑排序
	void Output1(Graph* p, int toplogicalSort_reslut[]);//按各学期中的学习负担尽量均匀地制定教学计划
	void Output2(Graph* p, int toplogicalSort_reslut[]);//按尽可能短的时间完成学习制定教学计划
	void Display(Graph* p);                              //输出课程信息 
	int Menu();                                                      //程序菜单
private:
	Course course[COURSE_MAX_NUMBER];                                //课程信息 
	int course_number;                                               //课程数量
	int semester_number;											 //学期数
	int credit_max;													 //最大修读学分
	int re_number;													 //关系数
	int adjmatrix[COURSE_MAX_NUMBER][COURSE_MAX_NUMBER];             //邻接矩阵存放课程之间的关系
};
/*
int Transfer(char *ch){
	if(ch[1] == '0') return ch[2] - '1';
    else return (ch[1] - '0') * 10 + ch[2] - '1';
}*/

//文件形式输入课程信息创建图
void Graph::Create1(Graph* p)
{
	ifstream in("course_info.txt");
	in >> p-> semester_number >> p->credit_max >> p->course_number >> p->re_number;
	for (int i = 1;i <= p->course_number;i++){
		in >> p->course[i].id >> p->course[i].name >> p->course[i].credit;
		p->course[i].course_exist = true;
	}
	int i, j, k;
	//char *a, *b;
	for (k = 0; k < p->re_number; k++)                   
	{
		in >> i >> j;
		//i = Transfer(a);
		//j = Transfer(b);
		p->adjmatrix[i][j] = 1;                   //表示课程ci是课程cj的先修课程
	}
	in.close();
}

//键盘形式输入课程信息创建图
void Graph::Create2(Graph* p)
{
	cout << "请依次输入学期数、最大修读学分、课程总数和课程之间的关系数" << endl;
	//此处应当判断输入是否合法，比如对于AOV而言的边数是否合理
	cin >> p->semester_number >> p->credit_max >> p->course_number >> p->re_number;
	cout << "请依次输入课程编号、课程名称和学分" << endl;
	for (int i = 1;i <= p->course_number;i++)
	{
		cin >> p->course[i].id >> p->course[i].name >> p->course[i].credit;
		p->course[i].course_exist = true;
	}
	memset(p->adjmatrix, 0, sizeof(p->adjmatrix));       //初始化adjmatrix全部元素为0 
	cout << "请输入课程之间的前后关系" << endl;
	int i, j, k;
	//char *a, *b;
	for (k = 1;k <= p->re_number;k++)                      
	{
		cin >> i >> j;
		//i = Transfer(a);
		//j = Transfer(b);
		p->adjmatrix[i][j] = 1;                   
	}
}

//输出课程信息 
void Graph::Display(Graph* p){
	cout<<"课程信息："<<endl;
	for (int i = 1;i <= p->course_number;i++)
	{
		cout << p->course[i].id << " ";
		cout << p->course[i].name << " ";
		cout << p->course[i].credit << " ";
		cout << endl;
	}
	cout<<endl<<"课程关系矩阵："<<endl;
	for (int i = 1;i <= p->course_number;i++)
	{
		for (int j = 1;j <= p->course_number;j++)
			cout << p->adjmatrix[i][j] << " ";
		cout << endl;
	}
}

//修改课程信息
void Graph::Modify(Graph* p)
{
	int number, choice;
	cout << "请输入您想修改的课程编号：" << endl;
	cin >> number;
	cout << "您想修改的信息为(1.课程名称 2.课程学分)：" << endl;
	cin >> choice;
	if (choice == 1)
	{
		cout << "请输入新的课程名称" << endl;
		cin >> p->course[number].name;
	}
	if (choice == 2)
	{
		cout << "请输入新的课程学分" << endl;
		cin >> p->course[number].credit;
	}
	cout << "修改成功" << endl;
}

//构造拓扑序列
void Graph::Topology_sort(Graph* p, int toplogicalSort_reslut[])
{
	int indegree[p->course_number + 1];           //存放各结点的入度（从indegree[1]开始存放）
	memset(indegree, 0, sizeof(indegree));
	for (int i = 1;i <= p->course_number;i++)     //统计各结点的入度
		for (int j = 1;j <= p->course_number;j++)
			if (p->adjmatrix[i][j]) indegree[j]++;

	stack <int> s;
	for (int i = 1;i <= p->course_number;i++)     //入度为0，则压入栈
		if (!indegree[i]) s.push(i);

	int num = 0;                                  //开始进行拓扑排序
	while (!s.empty())                            //栈非空
	{
		int top;
		top = s.top();                            //取栈顶元素
		s.pop();                                  //出栈
		toplogicalSort_reslut[num++] = top;       //保存栈顶元素
		for (int j = 1;j <= p->course_number;j++)
		{
			if (p->adjmatrix[top][j])
			{
				if (!--indegree[j]) s.push(j);    //每出一个元素，则它指向的结点入度减1 
			}                                     //并判断是否为0，若为零则入栈 
		}
	}
}
	
//尽可能均匀地制定教学计划
void Graph::Output1(Graph* p, int toplogicalSort_reslut[])
{
	ofstream out("evendistri.txt");
	int average_credit = 0;
	for (int i = 1;i <= p->course_number;i++)     //计算课程总学分
	{
		average_credit += p->course[i].credit;
	}

	int remaine_credit = average_credit;          //remaining_credit为剩余总学分 
	average_credit /= p->semester_number;                       
	out << "平均学分为:" << average_credit << endl << endl;
	int term_number = 1, j = 0;                   //学期编号、拓扑序列的下标

	while (remaine_credit > 0)                    //总学分还剩余
	{
		int term_credit = 0;
		int term_remaine_credit = average_credit; //当前学期还能修的学分
		out << "第" << term_number << "学期:" << endl;
		if (remaine_credit > term_remaine_credit) //剩余总学分多于当前学期还能修的学分
		{
			while (term_remaine_credit > 0)       //当前学期还能修的学分还剩余
			{
				out << p->course[toplogicalSort_reslut[j]].id << " ";
				out << p->course[toplogicalSort_reslut[j]].name << " ";
				out << p->course[toplogicalSort_reslut[j]].credit << " ";

				term_remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
				remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
				term_credit += p->course[toplogicalSort_reslut[j]].credit;
				j++;
				out << endl;
			}
			term_number++;                        //当前学期没有还能修的学分，换下学期
		}
		else                                      //剩余总学分少于或等于当前学期还能修的学分
		{
			out << p->course[toplogicalSort_reslut[j]].id << " ";
			out << p->course[toplogicalSort_reslut[j]].name << " ";
			out << p->course[toplogicalSort_reslut[j]].credit << " ";

			term_remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
			remaine_credit -= p->course[toplogicalSort_reslut[j]].credit;
			term_credit += p->course[toplogicalSort_reslut[j]].credit;
			j++;
			out << endl;
		}
		out << "本学期总学分为：" << term_credit << endl << endl;
	}
	out << "学期总数为:" << term_number << endl;
	out.close();
}

//尽可能集中地完成学习制定教学计划
void Graph::Output2(Graph* p, int toplogicalSort_reslut[])
{
	ofstream out("condistri.txt");
	int term_credit;                              //学期总学分
	int term_number = 1;                          //学期编号
	int number = 0;                               //拓扑排序结果下标
	int remain_credit = 0;                        //剩余总学分
	for (int i = 1;i <= p->course_number;i++)     //计算课程总学分
	{
		remain_credit += p->course[i].credit;
	}

	while (remain_credit > p->credit_max)                   
	{ 
		term_credit = 0;
		out << "第" << term_number << "学期:" << endl;
		while (term_credit + p->course[toplogicalSort_reslut[number]].credit < p->credit_max)
		{                                         
			out << p->course[toplogicalSort_reslut[number]].id << " ";
			out << p->course[toplogicalSort_reslut[number]].name << " ";
			out << p->course[toplogicalSort_reslut[number]].credit << " " << endl;
			term_credit += p->course[toplogicalSort_reslut[number]].credit;
			remain_credit -= p->course[toplogicalSort_reslut[number]].credit;
			number++;
		}
		term_number++;
		out << "本学期总学分为：" << term_credit << endl << endl;
    }

	term_credit = 0;
	out << "第" << term_number << "学期:" << endl;  //总学分剩余小于最大学分时 
	while (remain_credit > 0)
	{
		out << p->course[toplogicalSort_reslut[number]].id << " ";
		out << p->course[toplogicalSort_reslut[number]].name << " ";
		out << p->course[toplogicalSort_reslut[number]].credit << " " << endl;
		term_credit += p->course[toplogicalSort_reslut[number]].credit;
		remain_credit -= p->course[toplogicalSort_reslut[number]].credit;
		number++;
	}
	out << "本学期总学分为：" << term_credit << endl << endl;
	out << "学期总数为:" << term_number << endl;
	out.close();
}

//程序菜单
int Graph::Menu()
{
	int i;
	do {
		system("cls");
		cout << "------------教学计划编制系统-----------|" << endl;
		cout << "|          1.文件形式读入课程信息      |" << endl;
		cout << "|          2.键盘形式读入课程信息      |" << endl;
		cout << "|          3.课程信息修改              |" << endl;
		cout << "|          4.课程信息输出              |" << endl;
		cout << "|          5.均匀地制定教学计划        |" << endl;
		cout << "|          6.集中地制定教学计划        |" << endl;
		cout << "|          7.退出程序                 |" << endl;
		cout << "|----------------END------------------" << endl;
		cout << "请输入您的选择：";
		cin >> i;
	} while (i < 1 || i > 7);
	return i;
}

//主函数
int main()
{
	int i;
	Graph graph, * p;
	p = (Graph*)malloc(sizeof(Graph));
	int toplogicalSort_reslut[20];
	memset(toplogicalSort_reslut, 0, sizeof(toplogicalSort_reslut));

    first:
	switch (graph.Menu())
	{
	    case 1:
	    {
		    system("cls");
		    graph.Create1(p);                               //文件形式输入课程信息创建图 
	    	system("pause");
	    	goto first;
	    }
	    case 2:
	    {
	    	system("cls");
	     	graph.Create2(p);                               //键盘形式输入课程信息创建图
	    	system("pause");
	    	goto first;
    	}
        case 3:
	    {
		    system("cls");
		    graph.Modify(p);                              //修改课程信息 
		    system("pause");
		    goto first;
	    }
	    case 4:
    	{
		    system("cls");
		    graph.Display(p);                        //输出课程信息 
		    system("pause");
	    	goto first;
	    }
    	case 5:
    	{
		    system("cls");
		    graph.Topology_sort(p, toplogicalSort_reslut);      //拓扑排序 
	    	graph.Output1(p, toplogicalSort_reslut);//按各学期中的学习负担尽量均匀地制定教学计划
		    system("pause");
	    	goto first;
	    }
    	case 6:
    	{
		    system("cls");
	    	graph.Topology_sort(p, toplogicalSort_reslut);       //拓扑排序 
	    	graph.Output2(p, toplogicalSort_reslut); //按尽可能短的时间完成学习制定教学计划
	    	system("pause");
	    	goto first;
	    }
	}
	cout << "感谢使用！"; 
	return 0;
}
