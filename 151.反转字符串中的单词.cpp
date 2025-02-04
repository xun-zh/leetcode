// @before-stub-for-debug-begin
#include "commoncppproblem151.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=151 lang=cpp
 *
 * [151] 反转字符串中的单词
 */

// @lc code=start
class Solution {
public:
  string reverseWords(string s) {
    string res{};
    for (int start = s.size() - 1; start >= 0; --start) {
      if (s[start] == ' ') {
        continue;
      }
      int end = start;
      while (end >= 0 && s[end] != ' ') {
        --end;
      }
      if (!res.empty()) {
        res.push_back(' ');
      }
      res.append(s, end +1, start - end);
      start = end;
    }

    return res;
  }
};
// @lc code=end
