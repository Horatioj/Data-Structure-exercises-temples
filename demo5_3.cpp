//第三周第5题，埃氏筛法


#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;
const int maxn = 100000100;
int a[maxn] , flag;
bool judgement[maxn];

void is_prime(int n)
{
	memset(judgement, 1, sizeof(judgement));
	judgement[0] = 0;
	judgement[1] = 0;
	for(int i = 2; i <= n; i++)
	{
		if(judgement[i])
		{
			a[flag++] = i;
		}
		for(int j = 0; j < flag && i * a[j] <= n; j++)
        	{
			judgement[i*a[j]] = 0;
			if(i % a[j]==0)  {break;} //保证每个合数被它最小的质因数筛去
        	}
	}
}
int main()
{
	int n;
	cin >> n;
	is_prime(n);
	cout << flag << endl;
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