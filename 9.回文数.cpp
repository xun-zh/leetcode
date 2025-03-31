/*
 * @lc app=leetcode.cn id=9 lang=cpp
 *
 * [9] 回文数
 */

// @lc code=start
class Solution {
public:
  bool isPalindrome(int x) {
    if (x < 0) {
      return false;
    }
    int temp = x;
    long long res = 0;
    while (temp != 0) {
      res *= 10;
      res += temp % 10;
      temp /= 10;
    }
    return x == res;
  }
};
// @lc code=end
