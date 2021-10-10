#include<iostream>
#include<cstring>
using namespace std;

struct{
    char name[100];
}stu[100];

int main(){
   char str1[8] = "王放";
   char str2[8] = "黄鹏兵\r";
   char str3[13];
   int  len ;

   strcpy( str3, str1);
   cout << "strcpy( str3, str1) : " << str3 << endl;
 
   strcat( str1, str2);
   cout << "strcat( str1, str2): " << str1 << endl;
 
   len = strlen(str1);
   cout << "strlen(str1) : " << len << endl;
 
   return 0;
}