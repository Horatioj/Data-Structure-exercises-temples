template<class Elem>
class Alist:public list <Elem>{
    private:
        int maxSize;
        int listSize;
        int curr;
        Elem *listArray;
    public:
        Alist(int size = DefaultListSize){
            maxsize = size; listSize = curr = 0;
            listArray = new Elem[ maxSize ];
        }
        ~ Alist(){delete [] listArray;}
        void clear(){listSize = curr = 0;}
        void Prev(){if (curr>0) curr--;}
        void Next(){if (curr<listSize - 1) curr++;}
        bool setPos(int pos);
        bool insert(const Elem it);
        bool append(const Elem it);
        bool remove(Elem &it);
};

//插入操作
template <class Elem>
bool Alist <Elem> :: insert(const Elem it){
    if(listSize == maxSize) return false;
    if((curr<0) || (curr > listSize - 1)) return false;
    for(int i = listSize; i > curr; i--) listArray[i] = listArray[i-1];
    listArray[curr] = it;
    listSize ++;
    return true;
}


//追加操作
template <class Elem> 
bool Alist <Elem>::append(const Elem it){
    if(listSize==maxSize) return false;
    listArray[listSize ++ ] = it;
    return true;
}

template <class Elem> 
bool Alist <Elem>::remove(Elem& it){
    if(listSize==0) return false;
    if((curr < 0) || (curr >= listSize - 1));
    it = listArray[curr];
    for(int i = curr; i< listSize - 1; i++); listArray[i] = listArray[i+1];
    listSize--;
    return true;
}