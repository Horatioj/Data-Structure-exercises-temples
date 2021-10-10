#include<iostream>
using namespace std;

struct TreeNode{
    TreeNode* LChild;
    int value;
    TreeNode* RChild;
};

TreeNode* init(int n) {
    TreeNode* Store[30] = {NULL};
    TreeNode* temp;
    for (int i = 0; i < n; i++) {
        temp = new TreeNode;
        cin >> temp->value;
        temp->LChild = NULL;
        temp->RChild = NULL;
        Store[i] = temp;
    }
    int flag = 0;
    TreeNode* p = NULL;
    while (!flag) {
        int min1 = 0, min2 = 0;
        int count = 0;
        for (int i = 0; i < n; i++) {       //这个循环就可以保证min1指的是最小的数
            if (Store[i] != NULL) {
                if ((Store[min1]->value) > Store[i]->value)
                    min1 = i;
            }
            else continue;
        }
        if (min1 == 0) min2 = 1;
        for (int i = 0; i < n; i++) {
            if (i == min1) continue;
            if (Store[min2] == NULL && min2 < n) min2++;
            if (Store[i] != NULL && Store[min2] != NULL) {
                if (Store[i]->value < Store[min2]->value)
                    min2 = i;
            }
            else continue;
        }
        temp = new TreeNode;
        temp->value = Store[min1]->value + Store[min2]->value;
        temp->LChild = Store[min1];
        temp->RChild = Store[min2];
        Store[min1] = temp;
        Store[min2] = NULL;
        for (int i = 0; i < n; i++) {
            if (Store[i] != NULL) {
                p = Store[i];
                count++;
            }
            else continue;
        }
        if (count == 1) {
            return p;
        }
    }
    //return p;
}

void PreScan(TreeNode* tree){
    if(tree == NULL) return 0;
    cout << tree -> value;
    if(tree -> LChild){
        cout << "(";
        PreScan(tree->LChild);
        cout << ",";
    }
    if(tree ->RChild){
        PreScan(tree->RChild);
        cout << ")";
    }
}

int WPL(TreeNode* tree, int length){
    TreeNode* p =tree;
    if(p==NULL) return 0;
    else{
        if(!p->LChild && !p->RChild) return p->value*length;
        else return WPL(p->LChild, length + 1) + WPL(p->RChild, length+1);
    }
}

void Huffmancode(TreeNode* huff, int length){
    TreeNode* p = huff;
    static int code[30];
    int i;
    if(p){
        if(!p->LChild && !p->RChild){
            for(i = 0; i < length; i++) cout << code[i];
            cout << " ";
        }
        else {
            code[length] = 0;
            Huffmancode(p->LChild, length + 1);
            code[length] = 1;
            Huffmancode(p->RChild, length + 1);
        }
    }
}

int main(){
    int n;
    int wpl = 0, length = 0;
    cin >> n;
    TreeNode* tree;
    tree = init(n);
    wpl = WPL(tree, wpl);
    cout << wpl << endl;
    PreScan(tree);
    cout<<"\n";
    Huffmancode(tree, length);
}