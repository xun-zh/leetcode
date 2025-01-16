#include <iostream>

/**
 * NOTE: 分析一下，可以不用真正模拟出 light 的亮灭，可以避免每次恢复 lights
 * NOTE: 为什么？ -> 原因有几点：
 * NOTE: 1. 一个按钮按两次等于没按，因为它产生的效果抵消了
 * NOTE: 2. 各个按钮按下的顺序不影响最终的结果，因为异或运算满足交换律
 */

using namespace std;

int lights[6][8]{0}; // HINT: 边缘扩大一圈，避免特殊情况
int press[6][8]{0};

// 到初始状态 void pressLight(int row, int col) {
// 分析一下会发现不需要真正模拟出press操作
//   lights[row][col] = (lights[row][col] + 1) % 2;
//   lights[row][col - 1] = (lights[row][col - 1] + 1) % 2;
//   lights[row][col + 1] = (lights[row][col + 1] + 1) % 2;
//   lights[row - 1][col] = (lights[row - 1][col] + 1) % 2;
//   lights[row + 1][col] = (lights[row + 1][col] + 1) % 2;
// }

bool tryPress() {
  for (int row = 2; row < 6; ++row) {
    for (int col = 1; col < 7; ++col) {
      press[row][col] =
          (lights[row - 1][col] + press[row - 2][col] + press[row - 1][col] +
           press[row - 1][col - 1] + press[row - 1][col + 1]) %
          2;
    }
  }
  // HINT: 验证最后一行是否全为 0
  for (int col = 1; col < 7; ++col) {
    if ((press[5][col] + press[4][col] + press[5][col - 1] +
         press[5][col + 1]) %
            2 !=
        lights[5][col]) {
      return false;
    }
  }
  return true;
}

int main() {
  // io: in
  for (int i = 1; i < 6; ++i) {
    for (int j = 1; j < 7; ++j) {
      cin >> lights[i][j];
    }
  }
  // NOTE: 只要第一行的状态定下来，剩下的行都会定下来，枚举第一行的状态即可
  // NOTE: 同理，按照列枚举也是一样的，且复杂度小一点
  for (int i = 0; i < 64; ++i) {  // HINT: 枚举第一行的64中情况 (按 / 不按)
    for (int c = 1; c < 7; ++c) { // HINT: 第一行的初始状态
      press[1][c] = (i >> (c - 1)) % 2;
      // if (press[1][c]) {
      //   pressLight(1, c);
      // }
    }
    if (tryPress()) {
      break;
    }
  }

  // io: out
  for (int i = 1; i < 6; ++i) {
    for (int j = 1; j < 7; ++j) {
      cout << press[i][j] << " ";
    }
    cout << "\n";
  }
  return 0;
}