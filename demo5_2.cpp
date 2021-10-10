//埃氏筛法求素数
/**
 * 筛法是一种高效的构造素数表的算法。
　先介绍一个数论的定理。设a>1,则a=p1^n1*p2^n2...pk^nk.其中p1、p2...pk是质数，
  n1、n2...是正整数，并且在不计顺序的情况下，该表示是唯一的。
　一个简单的近似线性的筛法Eratosthenes筛法（埃拉托斯特尼筛法）　：
  先用2去筛，即把2留下，把2的倍数剔除掉；再用下一个质数，也就是3筛，把3留下，把3的倍数剔除掉；
  接下去用下一个质数5筛，把5留下，把5的倍数剔除掉；不断重复下去......。

输入某个数N(N不大于10000)，输出小于N的所有质数，且按照从小到大排序，中间空格隔开。
输入：10
输出:2 3 5 7
 */

#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 100000100;
int a[maxn] , flag;
bool judgement[maxn];

void is_prime(int n)
{
	memset(judgement, 1, sizeof(judgement));   //初始化函数,将judgement清零
	judgement[0] = 0;
	judgement[1] = 0;
	for(int i = 2; i < n; i++)
	{
		for(int j = 2; i * j <= n; j++)
		{
			judgement[i*j] = 0;
		}
		if(judgement[i])
		{
			a[flag++] = i;
		}
	}
}

int main(void)
{
	int n;
	cin >> n;
	is_prime(n);
//	cout << flag << endl;
	for(int i = 0; i < flag; i++)
	{
		if(i < flag - 1)
		{
			cout << a[i] << " ";
		}
		else
		{
			cout << a[i];
		}
	}
	return 0;
}