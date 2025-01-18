/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */
#include <vector>
using namespace std;

// @lc code=start
class Solution {
public:
  int removeDuplicates(vector<int> &nums) {
    // HINT: 双指针
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[slow] != nums[fast]) {
        nums[++slow] = nums[fast];
      }
      fast++;
    }
    return slow + 1; // HINT: slow是下标，返回长度需要+1
  }
};
// @lc code=end
