#include <iostream>
using namespace std;

int main()
{
    double runoobArray[] = {1000, 2, 3.4, 17, 50};
    double *p;

    p = runoobArray;

    cout << "使用指针的数组值" << endl;
    for ( int i = 0; i < 5; i++)
    {
        cout << "*(p + " << i << ") : ";
        cout << *(p + i) << endl;
    }
    cout << "使用 runoobArray 作为地址的数组值" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << "*(runoobArray + " << i << ") : ";
        cout << *(runoobArray + i) << endl;
    }

    return 0;
}