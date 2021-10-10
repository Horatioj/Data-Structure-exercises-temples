#include<iostream>
using namespace std;

//以二进制数表示，二进制0000(全部在河的南岸)实现到达二进制1111(全部到达河的北岸), 最多16种状态
int humanLoc(int currLoc){
    if((currLoc&8) == 8) return 1;   //按位与判断二进制数第四位是否为1
    else return 0;
}

int wolfLoc(int currLoc){
    if((currLoc&4) == 4) return 1;
    else return 0;
}

int sheepLoc(int currLoc){
    if((currLoc&2) == 2) return 1;
    else return 0;
}

int vegeLoc(int currLoc){
    if((currLoc&1) == 1) return 1;
    else return 0;
}

//判断安全状态，其中，狼羊 0110(6)/1001(9)，羊菜1100(12)/0011(3)独处时为非安全状态, 以及狼羊菜0111(7)/1000(8)
bool isSafe(int currLoc){
    int a = humanLoc(currLoc), b = wolfLoc(currLoc), c = sheepLoc(currLoc), d = vegeLoc(currLoc);
    if(a != b && b == c) return false;
    else if( a != c && c == d) return false;
    else return true;
}

//将visited[16]数组中访问过的元素输出
void route(int visited[16]){
    int Loc = 15;
    while (Loc != -1){
        cout << Loc << "(";
        for(int i=3;i>=0;i--) cout << ((Loc>>i)&1);
        cout << ") ";
        Loc = visited[Loc];
    }
    cout << endl;
}

//判断下一个结点是否安全，是则递归
void Search(int currLoc, int visited[16]){
    if(visited[15] == -1){    
        for(int i = 1; i <= 8; i <<= 1){             //移位运算符
            if(((currLoc&8)!=0)==((currLoc&i)!=0)){
                int nextLoc = currLoc^(8|i);         //按位或，按位异或，寻找下一个安全结点
                if(isSafe(nextLoc) && visited[nextLoc] == -1){
                    int nextVisited[16];
                    for(int j = 0; j < 16; j++){
                        nextVisited[j] = visited[j];
                    }
                    nextVisited[nextLoc] = currLoc;
                    Search(nextLoc, nextVisited);    //递归调用
                }
            }
        }
    }
    else route(visited);
}

int main(){
    int visited[16];
    for(int i = 0; i < 16; i++){
        visited[i] = -1;      //未访问，初始化为-1
    }
    Search(0, visited);
}