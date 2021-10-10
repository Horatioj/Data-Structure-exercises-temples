#include<iostream>
#include<math.h>
using namespace std;

typedef struct node{
    double coe;
    int exp;
    struct node *next;
}node, *nodeList;
nodeList apoly, bpoly;

//ͷ���
int init(nodeList l){
    l = new node;
    l -> next = NULL;
    return 0;
}

/*
void insert(nodeList p, nodeList h){
    if(p -> coe == 0) delete p;
    nodeList q1, q2;
    q1 = h;
    q2 = h -> next;
    while(q2 && p -> exp > q2 -> exp){
        q1 = q2;
        q2 = q2 -> next;
    }
    if(q2 && p -> exp == q2 -> exp){
        q2 -> coe += p -> coe;
        delete p;
        if(! q2 -> coe){
            q1 -> next = q2 -> next;
            delete q2;
        }
    }
    else{
        p -> next = q2;
        q1 -> next = p;
    }
}
*/

void create(nodeList l, int n){
    nodeList s,pre,q;
    for(int i=1;i<=n;++i)          //��������n��������
    {
        s=new node;
        cin>>s->coe>>s->exp;
        pre=l;                 //���ڱ���q��ǰ������ֵΪͷ���
        q=l->next;             //q��ʼ��ָ����Ԫ���
        while(q&&q->exp>s->exp)  //ͨ���Ƚ�ָ���ҵ���һ��С��������ָ������*q
        {
            pre=q;
            q=q->next;
        }
        s->next=q;                  //��������s���뵽q����ǰ�����pre֮��
        pre->next=s;
    }
}

//����ʽ�ӷ���a+b
void plusP(nodeList p1, nodeList p2){
    nodeList pa = p1 -> next;
    nodeList pb = p2 -> next;
    nodeList pc = p1;
    nodeList temp;
    int sum;
    while(pa && pb){
        if(pa -> exp == pb -> exp){
            sum = pa -> coe + pb -> coe;
            if(sum != 0){
                pa -> coe = sum; 
                pc -> next = pa;
                pc = pa;
                temp = pb;
                pb = pb ->next;
                delete temp;
            }
            else{
                temp = pa;
                pa = pa -> next;
                delete temp;
                temp = pb;
                pb = pb -> next;
                delete temp;
            }
        }
        else if(pa -> exp > pb -> exp){
            pc -> next = pa;
            pc = pa;
            pa = pa -> next;
        }
        else{
            pc -> next = pb;
            pc = pb;
            pb = pb -> next;
        }
    }
    pc -> next = pa ? pa : pb;
    delete p2;   
}

//����ʽ������a-b
void minusP(nodeList p1, nodeList p2){
    nodeList pa = p1 -> next;
    nodeList pb = p2 -> next;
    nodeList pc = p1;
    nodeList temp;
    int sum;
    while(pa && pb){
        if(pa -> exp == pb -> exp){
            sum = pa -> coe - pa -> coe;
            if(sum != 0){
                pa -> coe = sum;
                pc -> next = pa;
                pc = pa;
                pa = pa -> next;
                temp = pb;
                pb = pb -> next;
                delete temp;
            }
            else{
                temp = pa;
                pa = pa -> next;
                delete temp;
                temp = pb;
                pb = pb -> next;
                delete temp;
            }
        }
        else if(pa -> exp > pb -> exp){
            pc -> next = pa;
            pc = pa;
            pa = pa -> next;
        }
        else{
            pb -> coe = 0 - pb -> coe;
            pc -> next = pb;
            pc = pb;
            pb = pb -> next;
        }
    }
    if(pc -> next = pa) pc -> next = pa;
    else{
        pc -> next = pb;
        while(pb){
            pb -> coe = 0 - pb -> coe;
            pb = pb -> next;
        }
    }
    delete p2;
}

void calc(nodeList n, double x){
    nodeList l;
    l = n -> next;
    double sum = 0;
    cout << "������x��ֵ";
    cin >> x;
    while(l){
        sum += l -> coe * pow(x, l -> exp);
        l = l -> next;
    }
    cout << "��x����ֵΪ��" << sum;
}

void printout(nodeList n){
    nodeList l;
    int num = 0;
    l = n -> next;
    if(l == NULL) cout << "0";
    else{
        while(l){
            l = l -> next;
            num++;
        }
        cout << num;
        l = n -> next;
        while(l){
            cout << ", " << l -> coe << ", "<< l -> exp;
            l = l -> next;
        }
    }
}

/* ��ָ����������
void sort(nodeList l){
    nodeList p, q, r, s;
    p = l -> next;
    l -> next = NULL;
    while(p != NULL){
        r = l;
        q = l -> next;
        while((q != NULL) && (q -> exp >= p -> exp)){
            r = q;
            q = q -> next;
        }
        s = p -> next;
        r -> next = p;
        p -> next = q;
        p = s;
    }
}
*/

int main(){
    nodeList a, b;
    init(a);
    init(b);
    double x;
    int n, m; 
    cout << "���������ʽa������������������ϵ����ָ��" << endl;
    cin >> n;
    create(a, n);
    cout << "���������ʽb������������������ϵ����ָ��" << endl;
    cin >> m;
    create(b, m);
    cout << "�����뽫Ҫ���е�����+��-" << endl;
    string o;
    cin >> o;
    if(o == "+") {
        plusP(a, b);
        printout(a);
        calc(a, x);
    }
    else if(o == "-"){
        minusP(a, b);
        printout(b);
        calc(b, x);
    }
    else cout << "���������";
    return 0;
}