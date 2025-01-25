// @before-stub-for-debug-begin
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @before-stub-for-debug-end
/**
 *
 * @lc app=leetcode.cn id=1 lang=cpp
 *
 * [1] 两数之和
 */

// @lc code=start
class Solution {
public:
  vector<int> twoSum1(vector<int> &nums, int target) {
    for (int i = 0; i < nums.size(); i++) {
      for (int j = i + 1; j < nums.size(); j++) {
        if (nums[i] + nums[j] == target) {
          return vector<int>{i, j};
        }
      }
    }
    return {};
  }

  /**
   * @brief
   * NOTE: 让时间复杂度小于O(n^2), 使用 hash map, 记录已访问的值与index的映射
   */
  vector<int> twoSum(vector<int> &nums, int target) {
    unordered_map<int, int>
        num2index{}; // HINT: 主动去找对应的数，而不是一味遍历
    for (int i = 0; i < nums.size(); i++) {
      if (num2index.find(target - nums[i]) != num2index.end()) {
        return vector{num2index[target - nums[i]], i};
      }
      num2index.insert({nums[i], i});
    }
    return {};
  }
};
// @lc code=end
