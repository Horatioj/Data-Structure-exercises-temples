/**多项式的加法
 * 2 1 2.4 0 3.2
 * 2 2 1.5 1 0.5
 * = 3 2 1.5 1 2.9 0 3.2
*/

#include<iostream>
#include<iomanip>
using namespace std;
double a[1000];
int main(){
    int n,k,x,m,count = 0;
    double y;
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        a[x] += y;
    }
    cin>>m;
    for(int i = 0; i < m; i++){
        cin>>x>>y;
        a[x] += y;
    }
    for(int i = 0; i < 1001; i++){
        if(a[i] != 0) count++;
    }
    cout<<count;
    for(int i = 1001; i >= 0; i--){
        if(a[i] != 0){
            cout<<" "<<i<<" "<<setiosflags(ios::fixed)<<setprecision(1)<<a[i];
        }
    }
    return 0;
}

/* 可执行
#include<stdio.h>
const int max = 1001;
double a[max] = {};
int main(){
    int k, n, count = 0;
    double coe;
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d%lf", &n, &coe);
        a[n] = coe;
    }
    scanf("%d", &k);
    for(int i = 0; i < k; i++){
        scanf("%d%lf", &n, &coe);
        a[n] += coe;
    }
    for(int i = 0; i < max; i++){
        if(a[i]) count++;
    }
    printf("%d", count);
    for(int i = max - 1; i >= 0; i--){
        if(a[i]) printf(" %d %.1f", i, a[i]);
    }
    return 0;
}
*/