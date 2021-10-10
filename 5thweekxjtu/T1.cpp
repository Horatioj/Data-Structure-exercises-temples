//第 5 周 / 编程题 - 新兵队列训练
/*
某部队进行新兵队列训练，将新兵从1开始按顺序依次编号，并排成一行横队，
训练的规则如下：从头开始1至2报数，凡报到2的出列，剩下的向小序号方向靠拢，再从头开始进行1至3报数，
凡报到3的出列，剩下的向小序号方向靠拢，继续从头开始进行1至2报数，
以后从头开始轮流进行1至2报数、1至3报数直到剩下的人数不超过三人为止。
编写程序，输入数N为最开始的新兵人数（20 < N < 6000），输出剩下的新兵最初的编号。

输入样例：

21

输出样例：

1 7 19

*/

#include<iostream>
using namespace std;
struct element {
	int festnum;
	int newnum;
};

void renum(element* list, int N ) {      //给他新的编号
	int n = 1;
	for (int i = 0; i < N; i++) {
		if (list[i].newnum != 0) {
			list[i].newnum = n;
			n++;
		}
	}
}                                                 

void gout(element* list, int N, int count, int& num) {
	for (int i = 0; i < N; i++) {
		if (list[i].newnum % count == 0 && list[i].newnum != 0) {
			list[i].newnum = 0;
			num--;
		}
	}
}

int main() {
	int N;
	element* list;
	int count = 2;
	cin >> N;
	list = new element[N];
	int num = N;
	for (int i = 0; i < N; i++) {
		list[i].festnum = i + 1;  //记录编号
		list[i].newnum = list[i].festnum;
	}                          //删除完一次就重新给一个编号

	while (num > 3) {
		gout(list, N, count, num);
	
		renum(list, N);
		
		if (count == 2) count = 3;
		else count = 2;
	}
	int x = 1;
	for (int i = 0; i < N; i++) {          //输出
		if (list[i].newnum != 0 && x != num) {
			cout << list[i].festnum<<" ";
			x++;
			continue;
		}
		if (list[i].newnum != 0 && x == num) {
			cout << list[i].festnum;
			break;
		}
	}
	delete[] list;
}


// 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
// 1 3 5 7 9 11 13 15 17 19 1~2
// 1 3 7 9 13 14 19         1~3
// 1 7 13 19                1~2
// 1 7 19                   1~3 到三人以内