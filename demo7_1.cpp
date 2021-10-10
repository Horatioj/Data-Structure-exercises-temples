//第三周第7题，一般回文数
/*
输入：整数N,基数b(两个数字之间用空格隔开)
输出：数字序列

样例：
27 2
Yes
1 1 0 1 1

121 5
No
4 4 1
*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n, b;
    cin >> n >> b;
    vector<int> ans, t;
    if(!n){
        cout << "Yes\n0";
    }
    else{
        while(n){
            ans.push_back(n % b);
            n /= b;
        }
        t = ans;
        reverse(ans.begin(), ans.end());
        bool flag = false;
        for(int i = 0; i < (int)ans.size() / 2; i++){
            if(ans[i] != t[i]){
                flag = true;
                break;
            }
        }
        printf("%s\n", flag ? "No" : "Yes");
        for(int i = 0; i < (int)ans.size(); i++){
            if(i == 0) cout << ans[i];
            else cout << " " << ans[i];
        }
    }
    return 0;
}