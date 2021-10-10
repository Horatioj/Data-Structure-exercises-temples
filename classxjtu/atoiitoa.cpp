//a to i -> ascii to integer
// i to a -> reverse;

 
#include <iostream>
using namespace std;
 
void itoa(int n,char* res)
{
	int flag=1;
	int i=0,j=0;
	char buf[100]="";
	if(n<0)
		res[i++]='-';//如果是负数，第一位就是‘-’，不是的话这句话不执行
	n=abs(n);
	while(n)
	{
		buf[j++]=n%10+'0';
		n=n/10;
	}
	j--;
	while(j>=0)
		res[i++]=buf[j--];//倒序赋值给res
}
 
int main(){
	int num;
	char res[10]="";
	cin>>num;
	itoa(num,res);
	cout<<res<<endl;
	return 0;
}