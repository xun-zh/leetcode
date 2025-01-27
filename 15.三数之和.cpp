// @before-stub-for-debug-begin
#include "commoncppproblem15.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=15 lang=cpp
 *
 * [15] 三数之和
 */

// #include <algorithm>
// #include <unordered_map>
// #include <vector>

// using namespace std;

// @lc code=start
class Solution {
public:
  //   vector<vector<int>> threeSum_hash(vector<int> &nums) { // HINT:
  //   去重太麻烦
  //     auto res = vector<vector<int>>{};
  //     auto map_v2i = unordered_map<int, int>{};
  //     sort(nums.begin(), nums.end());
  //     for (int i = 0; i < nums.size(); ++i) {
  //       for (int j = i + 1; j < nums.size(); ++j) {
  //         if (map_v2i.find(-(nums[i] + nums[j])) != map_v2i.end()) {
  //           res.push_back({-(nums[i] + nums[j]), nums[i], nums[j]});
  //         }
  //       }
  //       map_v2i[nums[i]] = i;
  //     }
  //     return res;
  //   }

  vector<vector<int>> threeSum(vector<int> &nums) {
    auto res = vector<vector<int>>{};
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) { // HINT: 如果第一个数字就大于零，则不可能和为0
        return res;
      }
      if (i != 0 && nums[i] == nums[i - 1]) {
        // HINT: 和前面比较，而不是后面，
        // HINT: 防止跳过 -1 -1 2开头这种情况
        continue;
      }
      int left = i + 1;
      int right = nums.size() - 1;
      while (left < right) {
        if (nums[i] + nums[left] + nums[right] > 0) {
          --right;
        } else if (nums[i] + nums[left] + nums[right] < 0) {
          ++left;
        } else {
          res.push_back({nums[i], nums[left], nums[right]});
          // HINT: 找到
          while (right > left && nums[right] == nums[right - 1]) {
            --right;
          }
          while (right > left && nums[left] == nums[left + 1]) {
            ++left;
          }
          // HINT: 下一组
          --right;
          ++left;
        }
      }
    }
    return res;
  }
};
// @lc code=end
