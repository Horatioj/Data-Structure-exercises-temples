template <class Elem>
class Link{
Public:
    Elem element;
    Link *next;
    Link(const Elem &item, Link * nextval = NULL){element=item;next=nextval};
    Link(Link * nextval=NULL){next=nextval};
};

//带头结点的单链表
template <class Elem>
class LLink:public List<Elem>{
    Private:
    Link<Elem> * head;
    Link<Elem> * tail;
    Link<Elem> * curr;
    Void init(){
        curr = tail = head = new Link<Elem>;
    } //初始化一个空表
    Void removall(){
        while(head != NULL){
            curr = head;
            head = head -> next;
            delete curr;
        }
    }
Public:
    LList(){init();}
    ~LLink(){removeall();}
    void Create(int n);
    bool getValue(Elem &e);
    Link * Locate(Elem e);
    bool IsEmpty(){return(head->next == NULL);}
    void Prec();
    void Next();
    bool setPos(int pos);
    bool Insert(Elem x);
    bool remove(Elem &e);
    void clear(){removeall();init();}
    void Print();
};

void LList::Insert(Elem x){
    Link * s = new Link;
    if(!s){cout<<"空间分配失败"<<endl;return false;}
    s -> element = x;
    s -> next = curr -> next;
    curr -> next = s;
    return true;
}

void LList::Remove(Elem &e){
    if(curr->next == NULL) return false;
    Link *q = curr -> next;
    curr -> next = q ->next;
    e = q -> element;
    delete q;
    return true;
}