//HelloWorld for U
/*题目
Given any string of N (>=5) characters, you are asked to form the characters into the shape of U. 
For example, "helloworld!" can be printed as:
h     !
e     d
l      l
lowor

That is, the characters must be printed in the original order, 
starting top-down from the left vertical line with n1characters, 
then left to right along the bottom line with n2 characters, 
and finally bottom-up along the vertical line with n3 characters. 
And more, we would like U to be as squared as possible -- that is, 
it must be satisfied that n1 = n3 = max { k| k <= n2 for all 3 <= n2 <= N } with n1 + n2 + n3 - 2 = N.

Input Specification: Each input file contains one test case. 
Each case contains one string with no less than 5 and no more than 80 characters in a line. 
The string contains no white space. Output Specification: For each test case, 
print the input string in the shape of U as specified in the description.

Sample Input:

 helloworld!

Sample Output:

h     !
e     d
l      l
lowor

*/

/*#include <iostream>
#include <cstring>
int main() {
    char str[1000];
    scanf("%s", str);
    int
    N = (int)strlen(str),
    n1 = (N + 2) / 3,
    n2 = N + 2 - n1 - n1;
    if(N<5) return false;
    for(int i = 0; i < n1 - 1; i++){
        putchar(str[i]);
        for(int j = n2 - 3; j >= 0; j--){
            putchar(' ');
        }     
        putchar(str[N - i - 1]);
        putchar('\n');
    }
    for(int i = n1 - 1, l = n1 + n2 - 1; i < l; i++){
        putchar(str[i]);
    }
    return 0;
}*/
/*
#include <iostream>
#include <string.h>
using namespace std;
int main() {
    char c[81], u[30][30];
    memset(u, ' ', sizeof(u));
    scanf("%s", c);
    int n = strlen(c) + 2;
    int n1 = n / 3, n2 = n / 3 + n % 3, index = 0;
    for(int i = 0; i < n1; i++) u[i][0] = c[index++];
    for(int i = 1; i <= n2 - 2; i++) u[n1-1][i] = c[index++];
    for(int i = n1 - 1; i >= 0; i--) u[i][n2-1] = c[index++];
    for(int i = 0; i < n1; i++) {
        for(int j = 0; j < n2; j++) 
            printf("%c", u[i][j]);
        printf("\n");
    }
    return 0;
}
*/

#include<stdio.h>
#include<string.h>

int main()
{
	char a[85];
	scanf("%s", a);
	int len = strlen(a); 
	int n1, n2;
	n1 = (len + 2) / 3;    //向下取整 
	n2 = len - 2 * n1 + 2;

	int p = 0, q = len - 1;
	for( int i = 0; i < n1 - 1; i++){
		printf("%c", a[p]);
		for(int j = 0; j < n2 - 2; j++){
			printf(" ");
		}	
		printf("%c\n", a[q]);
		p++;
		q--;
	}
	
	for( int i = p; i <= q; i++){
		printf("%c", a[i]);
	}
	
	return 0;
}