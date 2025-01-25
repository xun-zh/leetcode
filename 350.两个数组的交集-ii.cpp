/*
 * @lc app=leetcode.cn id=350 lang=cpp
 *
 * [350] 两个数组的交集 II
 */
#include <unordered_map>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
    auto res = vector<int>{};
    auto midMap = unordered_map<int, int>{};
    for (int num : nums1) {
      ++midMap[num];
    }
    for (int num : nums2) {
      if (midMap[num] > 0) {
        --midMap[num];
        res.emplace_back(num);
      }
    }
    return res;
  }
};
// @lc code=end
