#include <stdio.h>
int main() {
  float x;                        // 定义一个float类型的变量x
  scanf("%f", &x);                // 从标准输入读取一个实数赋值给x
  printf("%6.2f\n", x);           // 第一行输出x
  printf("%6.2f %6.2f\n", x, x);  // 第二行输出x两次，用空格分隔
  printf("%6.2f %6.2f %6.2f\n", x, x, x);  // 第三行输出x三次，用空格分隔
  return 0;
}