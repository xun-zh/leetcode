// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/**
 * @lc app=leetcode.cn id=283 lang=cpp
 *
 * [283] 移动零
 */

// @lc code=start
class Solution {
public:
  /**
   * @brief
   * NOTE: 双指针, 一个指针指向第一个0，第二个指向连续0后的第一个非0
   */
  void moveZeroes(vector<int> &nums) {
    // HINT: firstZeroP始终指向第一个0的位置，
    int firstZeroP = 0, notZeroP = 0;
    while (notZeroP < nums.size()) {
      while (firstZeroP < nums.size() && nums[firstZeroP] != 0) {
        ++firstZeroP;
      }
      notZeroP = (notZeroP > firstZeroP ? notZeroP : firstZeroP + 1);
      while (notZeroP < nums.size() && nums[notZeroP] == 0) {
        ++notZeroP;
      }
      if (firstZeroP >= nums.size() || notZeroP >= nums.size()) {
        return;
      }
      // swap
      swap(nums[firstZeroP], nums[notZeroP]);
      // nums[firstZeroP] = nums[notZeroP];
      // nums[notZeroP] = 0;
    }
  }
};
// @lc code=end
