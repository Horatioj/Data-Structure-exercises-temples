/*某城市最高的楼有一部电梯，该电梯依照输入楼层数的先后次序运行。
电梯最初在0层。运行完一个输入序列后就停止在该楼层，不返回0层。
编写程序计算电梯运行一个序列的时间。电梯每上1层需要6秒。
每下1层需要4秒。如在某层停留，无论上下人多少，均停留5秒。*/

#include<stdio.h>
int main(){
    int current_floor, next_floor, sum;
    current_floor = 0;
    sum = 0;
    scanf("%d", &next_floor);
    while(next_floor){
        int diff = next_floor - current_floor;
        if(diff>0){
            sum = sum + diff*6;
        }
        if(diff<0){
            sum = sum + (-diff)*4;
        }
        sum = sum + 5;
        current_floor = next_floor;
        scanf("%d", &next_floor);
    }
    printf("%d", sum);
}