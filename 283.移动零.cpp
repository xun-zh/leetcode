/**
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

#include "common.h"

// @lc code=start
class Solution {
public:
  void moveZeroes(vector<int> &nums) {
    int firstZeroP, notZeroP = 0;
    while (notZeroP < nums.size()) {
      while (nums[firstZeroP] != 0 && firstZeroP < nums.size() - 1) {
        ++firstZeroP;
      }
      notZeroP = notZeroP > firstZeroP ? notZeroP : firstZeroP + 1;
      while (nums[notZeroP] == 0 && notZeroP < nums.size() - 1) {
        ++notZeroP;
      }
      // swap
      nums[firstZeroP] = nums[notZeroP];
      nums[notZeroP] = 0;
    }
  }
};
// @lc code=end
