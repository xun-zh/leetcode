/*
 * @lc app=leetcode.cn id=349 lang=cpp
 *
 * [349] 两个数组的交集
 */
#include <unordered_set>
#include <vector>

using namespace std;
// @lc code=start
class Solution {
public:
  vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
    auto res = vector<int>{};
    auto midSet = unordered_set<int>{};
    for (int num : nums1) {
      midSet.insert(num);
    }
    for (int num : nums2) {
      if (midSet.find(num) != midSet.end()) {
        midSet.erase(num);
        res.emplace_back(num);
      }
    }
    return res;
  }
};
// @lc code=end
