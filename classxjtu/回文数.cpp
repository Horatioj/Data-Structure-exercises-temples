#所谓对称数，就是譬如：1，323，34543之类的数。
#可以把原来的数的高低位互换，构造一个新的数，如果和原来的数相等则是对称数。
#输入一个数如果是对称数，返回1，否则返回0

#include <stdio.h>
#include <string.h>

int main()
{
  int i, length, flag = 1;
  char a[100];
  gets(a);
  length = strlen(a);
  for (i = 0; i <= length / 2; i++)
  {
    if (a[i] != a[length - i - 1])
    {
      flag = 0;
      break;
    }
  }
  if (flag == 1)
    printf("1");
  else
    printf("0");
  return 0;
}