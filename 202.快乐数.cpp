// @before-stub-for-debug-begin
#include "commoncppproblem202.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=202 lang=cpp
 *
 * [202] 快乐数
 */

#include <unordered_set>

using namespace std;

// @lc code=start
class Solution {
public:
  bool isHappy(int n) {
    // HINT: 思考如果一直迭代下去是否可能一直变大而不出现循环？
    auto appeared = unordered_set<int>{n};
    int remainder, intpartm, sqSum = 0, num = n;
    while (true) {
      while (num) {
        remainder = num % 10;
        sqSum += remainder * remainder;
        num /= 10;
      }
      if (sqSum == 1) {
        return true;
      }
      if (appeared.find(sqSum) != appeared.end()) {
        // HINT: 出现循环
        return false;
      }
      appeared.insert(sqSum);
      num = sqSum;
      sqSum = 0;
    }
  }
};
// @lc code=end
