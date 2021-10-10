#if defined(_MSC_VER) && !defined(_CRT_SECURE_NO_DEPRECATE)
#define _CRT_SECURE_NO_DEPRECATE
#endif
#include<iostream>
#include<iomanip>
#include<string.h>
#include<algorithm>
#include<fstream>
using namespace std;

class GradeList{
private:
    int id;
    char name[20];
    float math;
    float en;
    float com;
    float avg;
public:
    friend void write(GradeList stu[]);
    friend int read(GradeList stu[]);
    friend void input(GradeList stu[]);
    friend void sort_avg(GradeList stu[]);
    friend void output(GradeList stu[]);
    friend void output_math(GradeList stu[]);
    friend void output_en(GradeList stu[]);
    friend void output_com(GradeList stu[]);
    friend void search(GradeList stu[]);
        
}stu[100];

void write(GradeList stu[], int i){
    int cnt = i;
    fstream file;
    file.open("GradeList.txt", ios::out | ios::binary);
    if(!file){
        cout << "文件不存在！" << endl;
        abort();     //中止
    }
    file << cnt << endl;
    for(int j = 0; j < cnt; j++){
        file << stu[j].id << "\t" << stu[j].name << "\t" << stu[j].math << "\t"
             << stu[j].en << "\t" << stu[j].com  << endl;
    }
    file.close();
}

int read(GradeList stu[]){
    int cnt, i;
    fstream file;
    file.open("GradeList.txt", ios::in | ios::binary);
    if(!file){
        cout << "文件不存在！" << endl;
        abort();     //中止
    }
    file.seekg(0);
    file >> cnt;
    for(i = 0; i <= cnt; i++){
        file >> stu[i].id >> stu[i].name >> stu[i].math >> stu[i].en >> stu[i].com; 
    }
    file.close();
    return cnt;
}

void input(GradeList stu[]){
    system("cls");
    int i = 0;
    int flag = 0;
    char sign = '0';
    cout << "----------请输入学生成绩----------" << endl;
    cout << "请输入学生人数：";
    cin >> stu.num;
    while(sign != 'n' && sign != 'N'){
        loop:
            int c = 0;
            cout << "学号：";
            cin >> stu[i].id;
            while(c < i){
                c++;
                if(stu[i].num == stu[i-c].num){
                    cout << "学号已存在！请重新输入" << endl;
                    goto loop;
                }
            }
            cout << "姓名：";
            cin >> stu[i].name;
            do{
                cout << "数学成绩：" << endl;
                cin >> stu[i].math;
                if(stu[i].math < 0 || stu[i].math > 100){
                    cout << "成绩错误！" << endl;
                }
                else{
                    flag = 1;
                }
            }while(flag == 0);
            do{
                cout << "英语成绩：" << endl;
                cin >> stu[i].en;
                if(stu[i].en < 0 || stu[i].en > 100){
                    cout << "成绩错误！" << endl;
                }
                else{
                    flag = 1;
                }
            }while(flag == 0);
            do{
                cout << "计算机成绩：" << endl;
                cin >> stu[i].com;
                if(stu[i].com < 0 || stu[i].com > 100){
                    cout << "成绩错误！" << endl;
                }
                else{
                    flag = 1;
                }
            }while(flag == 0);
            stu[i].avg = (stu[i].math + stu[i].en + stu[i].com)/3.0;
            cout << "是否继续输入学生成绩?(y/n)";
            cin >> sign;
            i++;
    }
    write(stu, i);
}

void sort_avg(GradeList stu[]){
    system("cls");
    int i, j, k;
    char c[20];
    float score;
    int num = read(stu);
    for(i = 0; i < num-1; i++){
        for(j = 0; j < num-1; j++){
            if(stu[j].avg < stu[j+1].avg){
                
                strcpy(c, stu[j+1].name);
                strcpy(stu[j+1].name, stu[j].name);
                strcpy(stu[j].name, c);

                k = stu[j+1].id;
                stu[j+1].id = stu[j].id;
                stu[j].id = k;

                score = stu[j+1].math;
                stu[j+1].math = stu[j].math;
                stu[j].math = score;

                score = stu[j+1].en;
                stu[j+1].en = stu[j].en;
                stu[j].en = score;

                score = stu[j+1].com;
                stu[j+1].com = stu[j].com;
                stu[j].com = score;
            }
        }
    }
    write(stu, num);
}

void output(GradeList stu[]){
    sort_avg(stu);
    system("cls");
    int n = read(stu);
    cout << "----------学生成绩表----------" << endl;
    if(!stu){
        cout << "没有成绩记录";
    }
    else{
        cout << "------------------------------------------------------------" << endl;
        cout << "学号" << "\t" << "姓名" << "\t" << "数学" << "\t" << "英语" << "\t" 
             << "计算机" << "\t" << "平均分" << endl;
        cout << "------------------------------------------------------------" << endl;
        for(int i = 0; i < n; i++){
            cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].math << "\t"
                 << stu[i].en << "\t" << stu[i].com << "\t" << stu[i].avg << endl;
        }
        cout << "------------------------------------------------------------" << endl;
    }
}

void output_math(GradeList stu[]){                             //GradeList stu[]
    int i, j, k;
    int count[5] = {0, 0, 0, 0, 0};
    int num = read(stu);
    char c[20];
    float score, avg_m, s;
    s = 0;
    cout << "----------数学成绩----------" << endl;
    for(i = 0; i < num-1; i++){
        for(j = 0; j < num-1; j++){
            if(stu[j].math < stu[j+1].math){
                
                strcpy(c, stu[j+1].name);
                strcpy(stu[j+1].name, stu[j].name);
                strcpy(stu[j].name, c);

                k = stu[j+1].id;
                stu[j+1].id = stu[j].id;
                stu[j].id = k;

                score = stu[j+1].math;
                stu[j+1].math = stu[j].math;
                stu[j].math = score;

            }
        }
        s += stu[i].math;
    }
    //按区间计数
    for(i = 0; i < num-1; i++){
        if(stu[i].math < 60){
            count[0]++;
        }
        else if(stu[i].math >= 60 && stu[i].math < 70){
            count[1]++;
        }
        else if(stu[i].math >= 70 && stu[i].math < 80){
            count[2]++;
        }
        else if(stu[i].math >= 80 && stu[i].math < 90){
            count[3]++;
        }
        else if(stu[i].math >= 90 && stu[i].math < 100){
            count[4]++;
        }
        else cout << "成绩有误！" << endl;
    }
    
    avg_m = s/num*1.0;
    cout << "-------------------------------------" << endl;
    cout << "学号" << "\t" << "姓名" << "\t" << "成绩" << endl;
    for(i = 0; i < num-1; i++){
        cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].math << endl;
    }
    cout << "平均分" << "\t" << avg_m << "\t" << "最高分" << *max_element(stu, stu+num) << "\t" << "最低分" << *min_element(stu, stu+num) << "\t"
            << "不及格人数" << "\t" << count[0] << "\t" << "60~69分人数" << count[1] << "\t" << "70~79分人数" << count[2] << "\t"
            << "80~89分人数" << "\t" << count[3] << "90分以上人数" << "\t" << count[4] << endl;
    cout << "-------------------------------------" << endl;
}

void output_en(GradeList stu[]){

}

void output_com(GradeList stu[]){

}

void search(GradeList stu[]){

}

void menu(){
    int d;
    while(d > 0 && d < 7){
        system("cls");
        cout << "------------学生成绩表------------" << endl;
        cout << "          【1】输入成绩           " << endl;
        cout << "          【2】输出成绩           " << endl;
        cout << "          【3】数学成绩           " << endl;
        cout << "          【4】英语成绩           " << endl;
        cout << "         【5】计算机成绩          " << endl;
        cout << "          【6】查询成绩           " << endl;
        cout << "          【0】推出查询           " << endl;
        cout << "-----------END-OF-LINE-----------" << endl;
        cout << "请输入您的操作(0~6)：" << endl;
        cin >> d;
    }
    return d;
}

int main(){
    for(;;){
        switch(menu()){
            case 1:
                input(stu);        //输入
                break;
            case 2:
                output(stu);      //输出平均成绩;
                break;
            case 3:
                output_math(stu); //输出数学成绩
                break;
            case 4:
                output_en(stu);   //输出英语成绩
                break;
            case 5:
                output_com(stu);  //输出计算机成绩
                break;
            case 6:
                search(stu);      //查询成绩
                system("pause");
                break;
            case 0:
                cout << "==========>> 感谢使用 <<==========" << endl;
        }
    }
} 