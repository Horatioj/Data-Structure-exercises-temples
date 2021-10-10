#include<iostream>
using namespace std;
class Hanoi{
public:
    void HanoiTower(int n, char a, char b, char c);
    void Move(int n, char s, char t);    //将圆盘n从塔座s移到塔座t上
};

void Hanoi::HanoiTower(int n, char a, char b, char c){
    if(n==1) Move(1, a, b);
    else{
        HanoiTower(n-1, a, c, b);   //先将n-1个移到b
        Move(n, a, b);
        HanoiTower(n-1, c, b, a);
    }
    return;
}

void Hanoi::Move(int n, char s, char t){
    cout << "将圆盘" << n << "从塔座" << s << "移动至" << t << endl;
    return;
}

int main(){
    Hanoi h;
    int n;
    cout << "请输入圆盘的个数：";
    cin >> n;
    h.HanoiTower(n, 'A', 'B', 'C');
    return 0;
}