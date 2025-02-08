// @before-stub-for-debug-begin
#include "commoncppproblem1047.h"
#include <stack>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=1047 lang=cpp
 *
 * [1047] 删除字符串中的所有相邻重复项
 */

// @lc code=start
class Solution {
public:
  string removeDuplicates(string s) {
    vector<char> stk;
    for (char ch : s) {
      if (stk.empty() || stk[stk.size() - 1] != ch) {
        stk.push_back(ch);
      } else {
        stk.erase(stk.end() - 1);
      }
    }
    return string(stk.begin(), stk.end());
  }
};
// @lc code=end
