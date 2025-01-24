// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=54 lang=cpp
 *
 * [54] 螺旋矩阵
 */

// @lc code=start
class Solution {
public:
  vector<int> spiralOrder(vector<vector<int>> &matrix) {
    // HINT: 模拟
    if (matrix.size() == 0) {
      return {};
    }
    int capacity = matrix.size() * matrix[0].size();
    auto res = vector<int>(capacity);
    int top = 0;
    int bottom = matrix.size() - 1;
    int left = 0;
    int right = matrix[0].size() - 1;
    for (int i = 0; i < capacity;) {
      // top
      for (int m = left; m <= right && i < capacity; m++) {
        res[i++] = matrix[top][m];
      }
      top++;
      // right
      for (int m = top; m <= bottom && i < capacity; m++) {
        /* code */
        res[i++] = matrix[m][right];
      }
      right--;
      // bottom
      for (int m = right; m >= left && i < capacity; m--) {
        /* code */
        res[i++] = matrix[bottom][m];
      }
      bottom--;
      // left
      for (int m = bottom; m >= top && i < capacity; m--) {
        /* code */
        res[i++] = matrix[m][left];
      }
      left++;
    }
    return res;
  }
};
// @lc code=end
