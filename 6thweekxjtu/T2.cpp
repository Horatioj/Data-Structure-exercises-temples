/*
题目描述：
利用字符栈检查表达式的括号是否匹配。
提示：
从左向右扫描表达式，遇到“（”进栈，遇到“)”出栈，扫描完表达式后，若栈空，表示括号匹配。否则，
（1）当扫描完表达式后栈不空，可断定括号是不匹配的
（2）表达式未扫描完，需要出栈时栈是空的，此时可断定括号是不匹配的。
 
输入输出格式：
输入：一个表达式
输出：括号匹配！或 括号不匹配！
 
样例：
输入：
(a+b)*(5+c)*((22-c)/23+56)
输出：
括号匹配！
 
输入:
2+(5+8))
输出：
括号不匹配！
*/
#include <iostream>
using namespace std;

int isMatched(char left, char right);
int isParenthesesBalanced(char exp[]);

const int maxSize = 1000;

int main()
{
	char exp[maxSize];
	cin >> exp;
	if (isParenthesesBalanced(exp))
		cout << "括号匹配!" << endl;
	else
		cout << "括号不匹配!" << endl;
	return 0;
}

int isMatched(char left, char right)
{
	if (left == '(' && right == ')')
		return 1;
	else if (left == '[' && right == ']')
		return 1;
	else if (left == '{' && right == '}')
		return 1;
	else
		return 0;
}

int isParenthesesBalanced(char exp[])
{
	char s[maxSize];
	int top = -1;
	for (int i = 0; exp[i] != '\0'; i++)  /* '\0'文末*/
	{
		if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
			s[++top] = exp[i];
		if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
		{
			if (top == -1)
				return 0;
			char left = s[top--];
			if (!isMatched(left, exp[i]))
				return 0;
		}
	}
	if (top > -1)
		return 0;
	return 1;
}