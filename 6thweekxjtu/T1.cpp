/*#include<stdio.h>
#include<string.h>

int main(){
    char arr[100];
    char m;
    int alen;
    gets(arr);
    scanf("%c", &m);
    int len = strlen(arr);
    alen = len;
    for(int i = 0; i < len; i++){
        printf("%c", arr[i]);
    }
    printf("\n%d\n", len);
    //scanf("%c", &m);
    for (int i=0;i<len;i++){
        if(arr[i]==m){
            for(int j=i;j<len;j++)
                arr[j]=arr[j+1];
                alen--;
                i--;
        }
    }
    for (int i = 0; i<len; i++) printf("%c", arr[i]);
    printf("\n%d", alen);
}
*/

//#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<string.h>

int main() {
	char arr1[100], arr2[100];
	gets(arr1);
    int len = strlen(arr1);
	char m,j=0;
	scanf("%c", &m);
	for (int i = 0; i < len; i++)
	{
		if (arr1[i]!=m)
		{
			arr2[j] = arr1[i];
			j++;
		}
	}
	arr2[j] = '\0';
	printf("%s\n%d\n", arr1, len);
	printf("%s\n%d", arr2, j);
	return 0;
}