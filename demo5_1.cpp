#include<conio.h>
#include<stdio.h>
#include<stdlib.h>
#define MAX 10000

int find(int lim, int Prime[MAX]){
    int i, a=0, j=0;
    while(lim>1 && lim<=MAX){
        for (i=2;i<lim;i++)
        {
            if(lim%i == 0) a=1;
        }
        if (a == 0)
        {
            Prime[j++] = lim;
        }
        a = 0;
        lim --;
    }
    return j;
}

int main(){
    int limit, i , sum;
    int count = sum-1;
    int Prime[MAX];
    scanf("%d", &limit);
    //if(limit>10000||limit<=1){printf("the number should be within 2~10000");}
    //else{
    sum=find(limit, Prime);
    for(i=sum-1;i>=0;i--){
        if(i==0){
            printf("%d", Prime[i]);
        }else{
            printf("%d ", Prime[i]);
        }
    }
    //}
}