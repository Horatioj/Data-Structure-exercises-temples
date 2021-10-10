#include<iostream>
#include<cstdio>
using namespace std;

int fun(int m, int n){
    if(n==0) return m;
    return fun(n, m%n);
}
int main(){
    int n, m;
    cin>>m>>n;
    cout<<"最大公约数："<<fun(m, n)<<endl;
    return 0;
}

// int gcd(int m, int n){
//   return n ? gcd(n, m%n) : m;
// }