/*
 * @lc app=leetcode.cn id=69 lang=cpp
 *
 * [69] x 的平方根
 */

// @lc code=start
class Solution {
public:
  int mySqrt(int x) {
    if (!x)
      return 0;
    int left = 1, right = x;
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (mid == x / mid) { // HINT: 防止溢出
        return mid;
      } else if (mid < x / mid) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    // NOTE: 为什么返回right而不是left
    // NOTE: 返回的应该是整数部分，即向下取整，right是小于等于sqrt(x)的最大整数
    // NOTE: 因为 right 是减一之后不满足循环条件，left则是加一
    return right;
  }
};
// @lc code=end
