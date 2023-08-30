#include <iostream>

int main() {
  using namespace std;

  int a[11] = {0};
  for (int i = 1; i <= 10; i++) {
    cin >> a[i];
  }

  // 选择排序：首先找到最小的数，然后将其与第一个数交换，然后找到第二小的数，将其与第二个数交换，以此类推
  for (int i = 1; i <= 9; ++i) {
    int minn = a[i];  // minn 用于记录最小值

    for (int j = i + 1; j <= 10; j++) {  // 从 i+1 开始找最小值
      if (a[j] < minn) {  // 如果找到了更小的值，就更新 minn
        minn = a[j];
        swap(a[i], a[j]);  // 交换 a[i] 和 a[j]
      }
    }
  }

  for (int i = 1; i <= 10; i++) {
    cout << a[i] << " ";
  }

  return 0;
}
