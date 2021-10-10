#include<iostream>
using namespace std;

//�Զ���������ʾ��������0000(ȫ���ںӵ��ϰ�)ʵ�ֵ��������1111(ȫ������ӵı���), ���16��״̬
int humanLoc(int currLoc){
    if((currLoc&8) == 8) return 1;   //��λ���ж϶�����������λ�Ƿ�Ϊ1
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

//�жϰ�ȫ״̬�����У����� 0110(6)/1001(9)�����1100(12)/0011(3)����ʱΪ�ǰ�ȫ״̬, �Լ������0111(7)/1000(8)
bool isSafe(int currLoc){
    int a = humanLoc(currLoc), b = wolfLoc(currLoc), c = sheepLoc(currLoc), d = vegeLoc(currLoc);
    if(a != b && b == c) return false;
    else if( a != c && c == d) return false;
    else return true;
}

//��visited[16]�����з��ʹ���Ԫ�����
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

//�ж���һ������Ƿ�ȫ������ݹ�
void Search(int currLoc, int visited[16]){
    if(visited[15] == -1){    
        for(int i = 1; i <= 8; i <<= 1){             //��λ�����
            if(((currLoc&8)!=0)==((currLoc&i)!=0)){
                int nextLoc = currLoc^(8|i);         //��λ�򣬰�λ���Ѱ����һ����ȫ���
                if(isSafe(nextLoc) && visited[nextLoc] == -1){
                    int nextVisited[16];
                    for(int j = 0; j < 16; j++){
                        nextVisited[j] = visited[j];
                    }
                    nextVisited[nextLoc] = currLoc;
                    Search(nextLoc, nextVisited);    //�ݹ����
                }
            }
        }
    }
    else route(visited);
}

int main(){
    int visited[16];
    for(int i = 0; i < 16; i++){
        visited[i] = -1;      //δ���ʣ���ʼ��Ϊ-1
    }
    Search(0, visited);
}