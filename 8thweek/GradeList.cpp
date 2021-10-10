#include<iostream>
#include<cstring>
#include<iomanip>
#include<fstream>
using namespace std;

struct GradeList{
    int num;        //学生人数
    int id;
    char name[20];
    float math;
    float en;
    float com;
    float avg;
}stu[100], *GList;

void write(struct GradeList stu[], int i){
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
             << stu[j].en << "\t" << stu[j].com  << "\t" << stu[j].avg << endl;
    }
    file.close();
}

int read(struct GradeList stu[]){
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
        file >> stu[i].id >> stu[i].name >> stu[i].math >> stu[i].en >> stu[i].com >> stu[i].avg; 
    }
    file.close();
    return cnt;
}

int overlap(int i){
    int flag = 1;
    for(int j = 0; j < i; j++){
        if(stu[i].id == stu[j].id) flag = 0;
        else flag = 1;
    }
    return flag;
}

void input(struct GradeList stu[]){
    system("cls");
    int i = 0;
    int flag = 0;
    char sign = '0';
    cout << "----------请输入学生成绩----------" << endl;
    while(sign != 'n' && sign != 'N'){
        do{
            flag = 0;
            cout << "学号：";
            cin >> stu[i].id;
            if(overlap(i) == 0 || stu[i].id <= 0 || cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "学号错误！" << endl;
            }else flag = 1;
        }while(flag==0);
        
        cout << "姓名：";
        cin >> stu[i].name;

        do{
            flag = 0;
            cout << "数学成绩：";
            cin >> stu[i].math;
            if(stu[i].math < 0 || stu[i].math > 100 || cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "成绩错误！" << endl;
            }
            else flag = 1;
        }while(flag == 0);
        do{
            flag = 0;
            cout << "英语成绩：";
            cin >> stu[i].en;
            if(stu[i].en < 0 || stu[i].en > 100 || cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "成绩错误！" << endl;
            }
            else flag = 1;
        }while(flag == 0);
        do{
            flag = 0;
            cout << "计算机成绩：";
            cin >> stu[i].com;
            if(stu[i].com < 0 || stu[i].com > 100 || cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "成绩错误！" << endl;
            }
            else flag = 1;
        }while(flag == 0);
        stu[i].avg = (stu[i].math + stu[i].en + stu[i].com)/3.0;
        cout << "是否继续输入学生成绩?(y/n)";
        cin >> sign;
        i++;
    }
    write(stu, i);
}

void output(struct GradeList stu[]){
    system("cls");
    int n = read(stu);
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

                score = stu[j+1].avg;
                stu[j+1].avg = stu[j].avg;
                stu[j].avg = score;
            }
        }
    }

    cout << "----------学生成绩表----------" << endl;
    if(!stu){
        cout << "没有成绩记录！";
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
    write(stu, num);
}

void output_math(struct GradeList stu[]){                             //GradeList stu[]
    int i, j, k, min, max;
    int count[5] = {};
    min = max = stu[0].math;
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
    }

    for(i = 0; i < num; i++){
        s += stu[i].math;
    }
    avg_m = s/num*1.0;
    //按区间计数
    for(i = 0; i < num; i++){
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
        else if(stu[i].math >= 90 && stu[i].math <= 100){
            count[4]++;
        }
        else cout << "成绩有误！" << endl;
    }

    for(i = 0; i < num; i++){
        if(stu[i].math > max){
            max = stu[i].math;
            continue;
        }
        else if(stu[i].math < min){
            min = stu[i].math;
            continue;
        }
    }

    cout << "-------------------------------------" << endl;
    cout << "学号" << "\t" << "姓名" << "\t" << "成绩" << endl;
    for(i = 0; i < num; i++){
        cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].math << endl;
    }
    cout << "平均分" << "\t" << avg_m << "\t" << "最高分" << "\t" << max << "\t" << "最低分" << "\t" << min << "\t"
         << "不及格人数" << "\t" << count[0] << "\t" << "60~69分人数" << "\t" << count[1] << "\t" << "70~79分人数" 
         << "\t" << count[2] << "\t" << "80~89分人数" << "\t" << count[3] << "\t" << "90分以上人数" << "\t" << count[4] << endl;
    cout << "-------------------------------------" << endl;
}


void output_en(struct GradeList stu[]){
    int i, j, k, min, max;
    int count[5] = {};
    min = max = stu[0].en;
    int num = read(stu);
    char c[20];
    float score, avg_m, s;
    s = 0;
    cout << "----------英语成绩----------" << endl;
    for(i = 0; i < num-1; i++){
        for(j = 0; j < num-1; j++){
            if(stu[j].en < stu[j+1].en){
                
                strcpy(c, stu[j+1].name);
                strcpy(stu[j+1].name, stu[j].name);
                strcpy(stu[j].name, c);

                k = stu[j+1].id;
                stu[j+1].id = stu[j].id;
                stu[j].id = k;

                score = stu[j+1].en;
                stu[j+1].en = stu[j].en;
                stu[j].en = score;

            }
        }
    }

    for(i = 0; i < num; i++){
        s += stu[i].en;
    }
    avg_m = s/num*1.0;
    //按区间计数
    for(i = 0; i < num; i++){
        if(stu[i].en < 60){
            count[0]++;
        }
        else if(stu[i].en >= 60 && stu[i].en < 70){
            count[1]++;
        }
        else if(stu[i].en >= 70 && stu[i].en < 80){
            count[2]++;
        }
        else if(stu[i].en >= 80 && stu[i].en < 90){
            count[3]++;
        }
        else if(stu[i].en >= 90 && stu[i].en <= 100){
            count[4]++;
        }
        else cout << "成绩有误！" << endl;
    }

    for(i = 0; i < num; i++){
        if(stu[i].en > max){
            max = stu[i].en;
            continue;
        }
        else if(stu[i].en < min){
            min = stu[i].en;
            continue;
        }
    }

    cout << "-------------------------------------" << endl;
    cout << "学号" << "\t" << "姓名" << "\t" << "成绩" << endl;
    for(i = 0; i < num; i++){
        cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].en << endl;
    }
    cout << "平均分" << "\t" << avg_m << "\t" << "最高分" << "\t" << max << "\t" << "最低分" << "\t" << min << "\t"
         << "不及格人数" << "\t" << count[0] << "\t" << "60~69分人数" << "\t" << count[1] << "\t" << "70~79分人数" 
         << "\t" << count[2] << "\t" << "80~89分人数" << "\t" << count[3] << "\t" << "90分以上人数" << "\t" << count[4] << endl;
    cout << "-------------------------------------" << endl;
}

void output_com(struct GradeList stu[]){
    int i, j, k, min, max;
    int count[5] = {};
    min = max = stu[0].com;
    int num = read(stu);
    char c[20];
    float score, avg_m, s;
    s = 0;
    cout << "----------计算机成绩----------" << endl;
    for(i = 0; i < num-1; i++){
        for(j = 0; j < num-1; j++){
            if(stu[j].com < stu[j+1].com){
                
                strcpy(c, stu[j+1].name);
                strcpy(stu[j+1].name, stu[j].name);
                strcpy(stu[j].name, c);

                k = stu[j+1].id;
                stu[j+1].id = stu[j].id;
                stu[j].id = k;

                score = stu[j+1].com;
                stu[j+1].com = stu[j].com;
                stu[j].com = score;

            }
        }
    }

    for(i = 0; i < num; i++){
        s += stu[i].com;
    }
    avg_m = s/num*1.0;
    //按区间计数
    for(i = 0; i < num; i++){
        if(stu[i].com < 60){
            count[0]++;
        }
        else if(stu[i].com >= 60 && stu[i].com < 70){
            count[1]++;
        }
        else if(stu[i].com >= 70 && stu[i].com < 80){
            count[2]++;
        }
        else if(stu[i].com >= 80 && stu[i].com < 90){
            count[3]++;
        }
        else if(stu[i].com >= 90 && stu[i].com <= 100){
            count[4]++;
        }
        else cout << "成绩有误！" << endl;
    }

    for(i = 0; i < num; i++){
        if(stu[i].com > max){
            max = stu[i].com;
            continue;
        }
        else if(stu[i].com < min){
            min = stu[i].com;
            continue;
        }
    }

    cout << "-------------------------------------" << endl;
    cout << "学号" << "\t" << "姓名" << "\t" << "成绩" << endl;
    for(i = 0; i < num; i++){
        cout << stu[i].id << "\t" << stu[i].name << "\t" << stu[i].com << endl;
    }
    cout << "平均分" << "\t" << avg_m << "\t" << "最高分" << "\t" << max << "\t" << "最低分" << "\t" << min << "\t"
         << "不及格人数" << "\t" << count[0] << "\t" << "60~69分人数" << "\t" << count[1] << "\t" << "70~79分人数" 
         << "\t" << count[2] << "\t" << "80~89分人数" << "\t" << count[3] << "\t" << "90分以上人数" << "\t" << count[4] << endl;
    cout << "-------------------------------------" << endl;
}

void search(struct GradeList stu[]){
    system("cls");
    int num = read(stu);
    int id, d, i;
    i = 0;
    char name[20];
    cout << "----------学生成绩查询----------" << endl;
    cout << "请选择按学号查找(1)或按姓名查找(2)" << endl;
    cin >> d;
    if(d == 1){
        cout << "请输入学号：" << endl;
        cin >> id;
        while((stu[i].id - id) != 0 && i < num) i++;
        if(i == num) cout << "查无此人！" << endl;
        else{
            cout << "学号" << "\t" << stu[i].id << "\t" << "姓名" << "\t" << stu[i].name << "\t" 
                 << "数学成绩" << "\t" << stu[i].math << "\t" << "英语成绩" << "\t" << stu[i].en << "\t"
                 << "计算机成绩" << "\t" << stu[i].com << "\t" << "平均成绩" << "\t" << stu[i].avg << endl;
        }
    }
    else if(d == 2){
        cout << "请输入姓名：" << endl;
        cin >> name;
        for(i = 0; i < num; i++){
            int count = 0;
            if(strcmp(stu[i].name, name) == 0){
                cout << "学号" << "\t" << stu[i].id << "\t" << "姓名" << "\t" << stu[i].name << "\t" 
                     << "数学成绩" << "\t" << stu[i].math << "\t" << "英语成绩" << "\t" << stu[i].en << "\t"
                     << "计算机成绩" << "\t" << stu[i].com << "\t" << "平均成绩" << "\t" << stu[i].avg << endl;
                count++;
            }
            if(count == 0 && i == num) cout << "查无此人！" << endl;
        }
    }
    else cout << "输入错误！" << endl;
}

void insert(struct GradeList stu[]){
    system("cls");
    int num = read(stu);
    int flag;
    char sign = '0';
    while(sign != 'n' && sign != 'N'){
        do{
            flag = 0;
            cout << "学号：";
            cin >> stu[num].id;
            /*
            if(cin.fail()){ 
                cin.clear();
                cin.ignore();
                cout << "学号错误！" << endl;
                cin >> stu[num].id;
            }*/
            if(overlap(num) == 0 || stu[num].id <= 0 || cin.fail()){
                cout << "学号错误！" << endl;
                cin.clear();
                cin.ignore();
            }else flag = 1;
        }while(flag == 0);

        cout << "姓名：";
        cin >> stu[num].name;

        do{
            flag = 0;
            cout << "数学成绩：";
            cin >> stu[num].math;
            if(stu[num].math < 0 || stu[num].math > 100 || cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "成绩错误！" << endl;
            }
            else flag = 1;
        }while(flag == 0);
        do{
            flag = 0;
            cout << "英语成绩：";
            cin >> stu[num].en;
            if(stu[num].en < 0 || stu[num].en > 100 || cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "成绩错误！" << endl;
            }
            else flag = 1;
        }while(flag == 0);
        do{
            flag = 0;
            cout << "计算机成绩：";
            cin >> stu[num].com;
            if(stu[num].com < 0 || stu[num].com > 100 || cin.fail()){
                cin.clear();
                cin.ignore();
                cout << "成绩错误！" << endl;
            }
            else flag = 1;
        }while(flag == 0);
        stu[num].avg = (stu[num].math + stu[num].en + stu[num].com)/3.0;
        num++;
        cout << "是否继续插入成绩(y/n)?";
        cin >> sign;
    }
    write(stu, num);
}

void delet(struct GradeList stu[]){
    system("cls");
    int num = read(stu);
    int i, j, id, d;
    i = j = 0;
    cout << "请输入需要删除学生成绩的学号：";
    cin >> id;
    while((stu[i].id - id) != 0 && i < num) i++;
    if(i == num) cout << "学号错误！" << endl;
    else{
        cout << "需要删除的学生成绩信息为：" << endl;
        cout << "学号" << "\t" << stu[i].id << "\t" << "姓名" << "\t" << stu[i].name << "\t" 
                 << "数学成绩" << "\t" << stu[i].math << "\t" << "英语成绩" << "\t" << stu[i].en << "\t"
                 << "计算机成绩" << "\t" << stu[i].com << "\t" << "平均成绩" << "\t" << stu[i].avg << endl;
        cout << "是否删除该同学信息？(是1/否0)" << endl;
        cin >> d;
        if(d == 1){
            for(j = i; j < num; j++){
                stu[j].id = stu[j+1].id;
                strcpy(stu[j].name, stu[j+1].name);
                stu[j].math = stu[j+1].math;
                stu[j].en = stu[j+1].en;
                stu[j].com = stu[j+1].en;
                stu[j].avg = stu[j+1].en;
            }
            cout << "删除成功！" << endl;
        }
        else cout << "请输入正确的指令" << endl;
    }
    write(stu, num-1);
}

void modify(struct GradeList stu[]){
    system("cls");
    int num = read(stu);
    int i, id, flag, score, s, d;
    i = flag = 0;
    while(!flag){
        cout << "请输入需要修改成绩的学号：";
        cin >> id;
        while((stu[i].id - id) != 0 && i < num) i++;
        if(i == num) cout << "学号错误！" << endl;
        else{
            cout << "需要修改的学生成绩信息为：" << endl;
            cout << "学号" << "\t" << stu[i].id << "\t" << "姓名" << "\t" << stu[i].name << "\t" 
                    << "数学成绩" << "\t" << stu[i].math << "\t" << "英语成绩" << "\t" << stu[i].en << "\t"
                    << "计算机成绩" << "\t" << stu[i].com << "\t" << "平均成绩" << "\t" << stu[i].avg << endl;
            cout << "请选择需要修改成绩的科目：" << endl;
            cout << "数学" << "\t" << 1 << "\t" <<"英语" << "\t" << 2 << "\t" << "计算机" << "\t" << 3 << endl;
            cin >> score;
            if(score == 1){
                cout << "请输入修改后数学的成绩：" << endl;
                cin >> s;
                cout << "您所修改的成绩为：" << s << " 是否确认修改？(是：1/否：0)";
                cin >> d;
                if(d == 1){
                    stu[i].math = s;
                    cout << "成绩修改成功！" << endl;
                    flag = 1;
                }   
                else if(d == 0) cout << "您撤销了修改数学成绩！" << endl; flag = 1;
            }
            else if(score == 2){
                cout << "请输入修改后英语的成绩：" << endl;
                cin >> s;
                cout << "您所修改的成绩为：" << s << " 是否确认修改？(是：1/否：0)";
                cin >> d;
                if(d == 1){
                    stu[i].en = s;
                    cout << "成绩修改成功！" << endl;
                    flag = 1;
                }   
                else if(d == 0) cout << "您撤销了修改英语成绩！" << endl; flag = 1;
            }
            else if(score == 3){
                cout << "请输入修改后计算机的成绩：" << endl;
                cin >> s;
                cout << "您所修改的成绩为：" << s << " 是否确认修改？(是：1/否：0)";
                cin >> d;
                if(d == 1){
                    stu[i].com = s;
                    cout << "成绩修改成功！" << endl;
                    flag = 1;
                }   
                else if(d == 0) cout << "您撤销了修改计算机成绩！" << endl; flag = 1;
            }
            else cout << "请输入正确的指令！" << endl;
        }
    }
    write(stu, num);
}


void menu(){
    cout << "*-----------学生成绩表-----------|" << endl;
    cout << "|         【1】输入成绩          |" << endl;
    cout << "|         【2】输出成绩          |" << endl;
    cout << "|         【3】数学成绩          |" << endl;
    cout << "|         【4】英语成绩          |" << endl;
    cout << "|         【5】计算机成绩        |" << endl;
    cout << "|         【6】查询成绩          |" << endl;
    cout << "|         【7】插入成绩          |" << endl;
    cout << "|         【8】删除成绩          |" << endl;
    cout << "|         【9】修改成绩          |" << endl;
    cout << "|         【0】退出查询          |" << endl;
    cout << "|--------------END--------------*" << endl;
}

int main(){
    int d;
    while(1){
        menu();
        cout << "请输入您的操作(0~9)：" << endl;
        cin >> d;
        switch(d){
            case 1:
                input(stu);        //输入，初次输入成绩
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
                break;
            case 7:
                insert(stu);      //插入成绩
                break;
            case 8:               //delete 删除成绩
                delet(stu);
                break;
            case 9:               //修改成绩
                modify(stu);
                break;
            case 0:
                cout << "==========>> 感谢使用 <<==========" << endl;
        }
        char ch;
        cout << endl;
        cout << "----------------------------------------------------------\n";
        cout << "                      是否继续(y/n)：";
        cin >> ch;
        if (ch == 'y'){
            system("cls");
            continue;
        }
        else
            exit(0); // 退出循环，程序结束
    } 
}