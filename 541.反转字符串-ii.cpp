/*
 * @lc app=leetcode.cn id=541 lang=cpp
 *
 * [541] 反转字符串 II
 */

// @lc code=start

#include <string>
using namespace std;
class Solution {
public:
  string reverseStr(string s, int k) {
    int i = 0;
    while (true) {
      int left = i * 2 * k;
      int right = min(left + k - 1, (int)s.size() - 1);
      if (left >= s.size()) {
        break;
      }
      reverse(s, left, right);
      ++i;
    }
    return s;
  }

  void reverse(string &s, int left, int right) {
    while (left < right) {
      swap(s[left], s[right]);
      left++;
      right--;
    }
  }
};
// @lc code=end
