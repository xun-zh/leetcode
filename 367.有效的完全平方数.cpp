/*
 * @lc app=leetcode.cn id=367 lang=cpp
 *
 * [367] 有效的完全平方数
 */

// @lc code=start
class Solution {
public:
  bool isPerfectSquare(int num) {
    // HINT: 二分查找
    int left = 1, right = num;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid == num / mid) {
        return num % mid == 0;
      } else if (mid < num / mid) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return false;
  }
};
// @lc code=end
