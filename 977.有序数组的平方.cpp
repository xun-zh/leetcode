/*
 * @lc app=leetcode.cn id=977 lang=cpp
 *
 * [977] 有序数组的平方
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> sortedSquares(vector<int> &nums) {
    int left = 0;
    int right = nums.size() - 1;
    vector<int> res(nums.size());
    while (left <= right) {
      // NOTE: 因为元素住是有序的，只是要考虑负数，
      // NOTE: 所以平方后最大值在两端，据此可以不用修改原数组
      if (abs(nums[left]) < abs(nums[right])) {
        res[right - left] = nums[right] * nums[right];
        --right;
      } else {
        res[right - left] = nums[left] * nums[left];
        ++left;
      }
    }
    return res;
  }
};
// @lc code=end
