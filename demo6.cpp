//求N！的尾部有多少个0
/*
N较大时，N！无法直接计算出来（超界了）。
如果N的阶乘为K和10的M次方的乘积，那么N!末尾就有M的0。如果将N的阶乘分解后，
那么N的阶乘可以分解为： 2的X次方，3的Y次方，5的Z次方，.....的乘积。由于10 = 2 * 5,
所以M只能和X和Z有关，每一对2和5相乘就可以得到一个10，于是M = MIN(X,Z)，
不难看出X大于Z，因为被2整除的频率比被5整除的频率高的多。所以可以把公式简化为M=Z。

由上面的分析可以看出，只要计算出Z的值，就可以得到N!末尾0的个数。那么Z的值如何得到呢？
请同学们自行思考。

输出输出格式
如
输入：5
输出：1
*/

#include <iostream>
using namespace std;
 
 
int main()
{
	int N;
	cin >> N;
	int count = 0;
	int iTemp;
	for (int i = 1; i <= N; i++){
		iTemp = i;
		while ((iTemp % 5) == 0)
		{
			count++;
			iTemp /= 5;
		}
	}
	cout << count << endl;
	return 0;
}