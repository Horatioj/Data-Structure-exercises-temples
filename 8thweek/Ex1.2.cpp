#include <iostream>
#include<math.h>
using namespace std;

typedef struct node
{
    float coe;        
    int exp;          
    struct node *next;
}node, *nodeList;
nodeList a, b;

//头结点 
int init(nodeList &l){
	l = new node;
	l -> next = NULL;	
	return 0;
}
 
void create(nodeList &l,int n)
{
    nodeList curr, p, q;
    for(int i = 1; i <= n; i++){
        curr = new node;
        cin >> curr -> coe >> curr -> exp;
        p = l;                
        q = l -> next;             
        while(q && q -> exp > curr -> exp)  //寻找较小指数项
        {
            p = q;
            q = q -> next;
        }
        curr -> next = q;                  
        p -> next = curr;
    }
}

//a+b
void addP(nodeList &p1,nodeList &p2)
{
    nodeList pa = p1 -> next;
    nodeList pb = p2 -> next;
    nodeList pc = p1;
    nodeList curr;
    int sum;
    while(pa && pb){
        if(pa -> exp == pb -> exp)
        {
            sum = pa -> coe + pb -> coe;
            if(sum != 0){
                pa -> coe = sum;
                pc -> next = pa;
                pc = pa;
                pa = pa -> next;
                curr = pb;
                pb = pb -> next;
                delete curr;
            }
            else{
                curr = pa;
                pa = pa -> next;
                delete curr;
                curr = pb;
                pb = pb -> next;
                delete curr;
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
    delete pb;
}

//a-b
void subP(nodeList &p1,nodeList &p2)
{
    nodeList pa = p1 -> next;
    nodeList pb = p2 -> next;
    nodeList pc = p1;
    nodeList curr;
    int sum;
    while(pa && pb)
    {
        if(pa -> exp == pb -> exp)
        {
            sum = pa -> coe - pb -> coe;
            if(sum != 0)
            {
                pa -> coe = sum;
                pc -> next = pa;
                pc = pa;
                pa = pa -> next;
                curr = pb; 
                pb = pb -> next;
                delete curr;
            }
            else
            {
                curr = pa;
                pa = pa -> next;
                delete curr;
                curr = pb;
                pb = pb -> next;
                delete curr;
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
    if(pc -> next = pa) pc->next= pa;
    else{
        pc -> next = pb;
        while(pb){
            pb -> coe = 0 - pb -> coe;
            pb = pb -> next;
        }
    }
    delete pb;
}

void calc(nodeList n, double x){
    nodeList l;
    l = n -> next;
    double sum = 0;
    cout << "请输入x的值";
    cin >> x;
    while(l){
        sum += l -> coe * pow(x, l -> exp);
        l = l -> next;
    }
    cout << "在x处的值为：" << sum;
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

/* 按指数降幂排列
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
    double x;
    init(a);
    init(b);
    int n,m;
    cout << "请输入多项式a的项数，并依次输入系数和指数：";
    cin >> n;
    create(a,n);
    cout << "请输入多项式b的项数，并依次输入系数和指数：";
    cin >> m; 
    create(b,m);
    cout << "请输入将要进行的运算+或-" << endl;
    string o;
    cin >> o;
    if(o == "+"){
        addP(a,b);
        printout(a);
        calc(a, x);
    }
    else if(o == "-"){
        subP(a,b);
        printout(a);
        calc(a, x);
    }
    else cout<<"运算符错误！";
    return 0;
}