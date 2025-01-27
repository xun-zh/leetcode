// @before-stub-for-debug-begin
#include "commoncppproblem454.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=454 lang=cpp
 *
 * [454] 四数相加 II
 */

// @lc code=start
class Solution {
public:
  int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3,
                   vector<int> &nums4) {
    auto map_12 = unordered_map<int, int>{};
    int count = 0;
    for (int &num1 : nums1) {
      for (int &num2 : nums2) {
        ++map_12[num1 + num2];
      }
    }
    for (int num3 : nums3) {
      for (int num4 : nums4) {
        if (map_12[-(num3 + num4)]) {
          count += map_12[-(num3 + num4)];
        }
      }
    }
    return count;
  }
};
// @lc code=end
