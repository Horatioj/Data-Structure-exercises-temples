#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
using namespace std;
int fa[50000];

struct edge{
    int s, e;
    int weight;
}Ed[50000];

bool cmp(edge a, edge b){
    return a.weight < b.weight;
}

int find(int x){
    if(fa[x] != x) return find(fa[x]);
    else return x;
}

int kruskal(int n, int m){
    int number_Edge = 0;
    int result = 0;
    for(int i = 0; i < n; i++){
        fa[i] = i;
    }
    sort(Ed, Ed + m, cmp);
    for(int i = 0; i < m; i++){
        int S = find(Ed[i].s);
        int E = find(Ed[i].e);
        if(S != E){
            fa[S] = E;
            result += Ed[i].weight;
            number_Edge ++;
            if(number_Edge == n - 1)
                break;
        }
    }
    if(number_Edge != n - 1)
        return false;
    else return result;
}

int main(){
    int n, m;

    cin >> n >> m;
    for(int i = 0; i < m; i++){
        cin >> Ed[i].s >> Ed[i].e >> Ed[i].weight;
    }
    cout << kruskal(n, m);
    return 0;
}