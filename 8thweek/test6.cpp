#include <iostream> 
using namespace std; 
int main(){
    char sign = '0';
    cout<<"请输入一个整数:";
    int a, flag;
    while(sign != 'n' || sign != 'N'){
        do{
            flag = 0;
            cout << "学号：";
            cin >> a;
            /*
            if(cin.fail()){
                cout << "学号错误！" << endl;
                cin.clear();
                cin.ignore();
            }*/
            if(a <= 0 || cin.fail()){
                cout << "学号错误！" << endl;
                cin.clear();
                cin.ignore();
                //flag = 1;
            }
            else cout << "成功！" << endl; flag = 1;
        }while(flag == 0);
        cout << "是否继续插入成绩(y/n)?";
        cin >> sign;
    }
}