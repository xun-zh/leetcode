/*
 * @lc app=leetcode.cn id=136 lang=cpp
 *
 * [136] 只出现一次的数字
 */
#include <vector>
using namespace std;
// @lc code=start
class Solution {
public:
  int singleNumber(vector<int> &nums) {
    // NOTE: 两个相同的数异或，其值为0
    int res = 0;
    for (int num : nums) {
      res ^= num;
    }
    return res;
  }
};
// @lc code=end
