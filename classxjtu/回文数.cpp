#��ν�Գ���������Ʃ�磺1��323��34543֮�������
#���԰�ԭ�������ĸߵ�λ����������һ���µ����������ԭ������������ǶԳ�����
#����һ��������ǶԳ���������1�����򷵻�0

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