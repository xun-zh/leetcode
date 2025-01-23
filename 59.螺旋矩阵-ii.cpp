// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=59 lang=cpp
 *
 * [59] 螺旋矩阵 II
 */

// @lc code=start
class Solution {
public:
  vector<vector<int>> generateMatrix(int n) {
    // HINT: 模拟
    auto res = vector<vector<int>>(n, vector<int>(n));
    int num = 1;
    // NOTE: 下面的四个组成遍历的一圈
    int top = 0;
    int bottom = n - 1;
    int left = 0;
    int right = n - 1;
    while (num <= n * n) {
      // HINT: top
      for (int i = left; i <= right; i++) {
        res[top][i] = num++;
      }
      top++;
      // HINT: right
      for (int i = top; i <= bottom; i++) {
        res[i][right] = num++;
      }
      right--;
      // HINT: bottom
      for (int i = right; i >= left; i--) {
        res[bottom][i] = num++;
      }
      bottom--;
      // HINT: left
      for (int i = bottom; i >= top; i--) {
        res[i][left] = num++;
      }
      left++;
    }
    return res;
  }
};
// @lc code=end
