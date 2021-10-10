//第 4 周 / 编程题 - 3位分隔

/*
请输入一个正整数（如：7654321），
然后将该整数按照标准的三位分节格式输出(逗号是西文的逗号，如 7,654,321）
*/


#include <iostream>
#include <math.h>
using namespace std;
int main()
{
	int n, i = 1;
	char a[20], *ptr;
	bool negative = false;
	ptr = a;
	cin >> n;
	if (n < 0){
		negative = true;
		n = abs(n);
	}
	do{
		if(i % 4){
			*ptr = n % 10 + '0';
			n = n / 10;
		}
		else *ptr = ',';
		ptr++;
		i++;
	}while(n);
	if (negative == true) cout << "-";
	do{
		ptr--;
		i--;
		cout << *ptr;
	}while(i > 1);
	cout << endl;
	return 0;
}