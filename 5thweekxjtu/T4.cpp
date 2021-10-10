/*
题目：分数求和
给定N个“分子/分母”形式的有理数，计算这些分数的和。

输入格式：第一行输入一个正整数N（<=100），然后下一行N个有理数“a1/b1 a2/b2…”，
其中所有的分子和分母都在“int”的范围内。如果有负数，则符号必须出现在分子的前面。

输出格式：输出最简单形式的和，“整数 分子/分母”，其中“整数”是和的整数部分，“分子”<“分母”，
分子和分母没有公因数。如果整数部分为0，则必须仅输出小数部分。

输入样例:

5

2/5

4/15

1/30

-1/30

8/3

输出样例:

3 1/3

*/

/*
#include<iostream>
#include<cmath>
using namespace std;

int GCD(int a, int b){
    if(b==0) return a;
    else return GCD(b, a%b);
}
int main(){
    int n, a, b, numerator, denominator, divisor;
    scanf("%d%d/%d", &n, &numerator, &denominator);
    for(int i = 1; i < n; i++){
        scanf("%d/%d", &a, &b);
        numerator = numerator * b + a * denominator;
        denominator *= b;
        divisor = GCD(abs(numerator), abs(denominator));
        numerator /= divisor;
        denominator /= divisor;
    }
    if(denominator<0){
        denominator = -denominator;
        numerator = -numerator;
    }
    if(numerator && numerator / denominator == 0) printf("%d/%d\n", numerator, denominator);
    else if (numerator%denominator == 0);
    else printf("%d %d/%d\n", numerator / denominator, numerator%denominator, denominator);
    return 0;
}
*/
/*
#include<iostream>
#include<cmath>
#include<stdio.h>
using namespace std;
//求最大公约数的函数 
long gcd(long a,long b){
  return a%b==0 ? b:gcd(b,a%b);
}

int main(){
	
	int N;
	cin>>N;
	int a[100];//分子 
	int b[100];//分母
	long s1=0;//分子的和 
	long s2=0; //最小公倍数，最后的分母，长整型注意是
	//输入要求和的数据
	for(int i=0;i<N;i++){
		scanf("%d/%d",&a[i],&b[i]);
	} 
	//求分母的最小公倍数
	s2=b[1];
	for(int i=1;i<N;i++){
		s2=s2*b[i]/gcd(s2,b[i]);
	}
	//分数通分之后求分子的和 
	for(int i=0;i<N;i++){
		s1=s1+s2/b[i]*a[i];
	}
	long long n=s1/s2,m=abs(s1%s2);
	if(m==0){
		//余数为零，说明结果是整数
		cout<<n<<endl; 
	}else{
		//余数不为零，结果有分数 
		//分数前面的整数部分 
		 if(n!=0){
		 	cout<<n<<" ";
		 }
		 //分子的和是负数 
		 if(s1<0){
		 	cout<<"-";
		 } 
		 //输出结果的最简形式 
		 cout<<m/gcd(s2,m)<<"/"<<s2/gcd(s2,m); 
	}
	return 0;
} 
*/

#include<iostream>
#include<cmath>
#include<math.h>
using namespace std;
int test(int t1, int t2)
{
    if(t1 == 0)
        return t2;
    else
        return test(t2 % t1, t1);
}
int main()
{
    int n;
    cin >> n;
    int a, b;
    int zi = 0, mu = 1;
    for(int i = 0; i < n; i++){
        scanf("%d / %d", &a,  &b);
        zi = zi * b + mu * a;
        mu = mu * b;
        int t1 = min(zi, mu);
        int t2 = max(zi, mu);
        zi /= test(t1, t2);
        mu /= test(t1, t2);
    }
    int x = zi / mu;
    if(x != 0)
    {
        cout << x;
        if(zi % mu != 0)
        {
            printf(" %d/%d", zi % mu, mu);
        }
    }
    else printf("%d/%d", zi % mu, mu);

}