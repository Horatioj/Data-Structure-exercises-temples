//函数模板求解：
//包括有整数的比较、浮点数的比较、双精度的比较。
//先有一个判断比较的类型，如果输入1，则为整数；2为浮点数；3为双精度。

/**如
输入：
1
1 2 3
输出：3
输入：
2
1.2 3.6 0
输出：3.6 
*/

#include <iostream>
using namespace std;
template<typename T>
T max(T a, T b, T c)
{
	T max;
	max = a>b ? a: b;
	max = max > c ? max: c;
	return max;
}
int main()
{
    int x;
    scanf("%d", &x);
    if(x==1){
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(a, b, c)<<endl;
    }
	if(x==2){
    double d, e, f;
	cin >> d >> e >> f;
	cout << max(d, e, f) << endl;
    }
    if(x==3){
	float j, k, l;
	cin >> j >> k >> l;
	cout << max(j, k, l) << endl;
    }
}
