// @before-stub-for-debug-begin
#include "commoncppproblem347.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */
// @lc code=start
class Solution {
public:
  vector<int> topKFrequent(vector<int> &nums, int k) { // TODO 堆排序
    unordered_map<int, int> freq;
    for (int num : nums) {
      freq[num]++;
    }
    vector<int> res;
    vector<pair<int, int>> vec;
    for (auto &p : freq) {
      vec.push_back(p);
    }
    auto cmp = [](const pair<int, int> &a, const pair<int, int> &b) {
      return a.second < b.second;
    };
    make_heap(vec.begin(), vec.end(), cmp);
    for (int i = 0; i < k; i++) {
      res.push_back(vec.front().first);
      pop_heap(vec.begin(), vec.end(), cmp);
      vec.pop_back();
    }
    return res;
  }
};
// @lc code=end
