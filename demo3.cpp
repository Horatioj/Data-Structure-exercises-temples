//���ú���ģ������������������
//�����������ıȽϡ��������ıȽϡ�˫���ȵıȽϡ�
//����һ���жϱȽϵ����ͣ��������1����Ϊ������
//2Ϊ��������3Ϊ˫���ȡ�

#include <iostream>
using namespace std;
template<typename T>
T max(T a, T b, T c)
{
	T max;
	max = a > b ? a : b;
	max = max > c ? max : c;
	return max;
}
int main()
{
    int x;
    scanf("%d", &x);
    if(x==1){
        int a, b, c;
        cin >> a >> b >> c;
        cout << max(a, b, c)<<endl;
    }
	if(x==2){
        double d, e, f;
        cin >> d >> e >> f;
        cout << max(d, e, f) << endl;
    }
    if(x==3){
        float j, k, l;
        cin >> j >> k >> l;
        cout << max(j, k, l) << endl;
    }
    if(x==4){
        char v, g, h;
        cin >> v >> g >> h;
        cout << max(v, g, h) << endl;
    }
}
