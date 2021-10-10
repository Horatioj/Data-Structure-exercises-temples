#include<iostream>
#define MAX 10000;
using namespace std;
bool is_prime[10000];

void init(){
    for(int i=2;i<10000;++i)
    {
        is_prime[i]=1;
    }    
} 
void judge_prime(){
    init();
    for(int i = 2; i*i<10000 ; ++i){
        if(is_prime[i]==1){
            for(int j = i*i ; j<10000;j+=i){
                is_prime[j] = 0;
            }
        }
    } 
}
int main() {

    judge_prime();
    int N;
    scanf("%d", &N);
    cout<<"\n";
    for(int i=2;i<N;++i)
    {
        if(i==N) {
            cout<<"\b"<<endl;
        }
        if(is_prime[i]==1)
        {
            cout<<i<<" ";
        }
    }
    return 0;
}