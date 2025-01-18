/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */
#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  int removeElement(vector<int> &nums, int val) {
    // HINT: 双指针, 暴力解跳过了
    // NOTE: 遇到要删除的元素，fast指针继续前进，slow指针停留
    // NOTE: 这样可以保证 slow 指针前的元素都是不等于 val 的
    // NOTE: 且 fast 和 slow 的插值是等于 val 的个数 (当前位置)
    // NOTE: fast 和 slow 之间的位置是无意义值(存被删除的元素)
    int slow = 0, fast = 0;
    while (fast < nums.size()) {
      if (nums[fast] != val) {
        nums[slow] = nums[fast];
        ++slow;
      }
      ++fast;
    }
    return slow;
  }
};
// @lc code=end
