// @before-stub-for-debug-begin
#include "commoncppproblem459.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=459 lang=cpp
 *
 * [459] 重复的子字符串
 */

// @lc code=start
class Solution {
public:
  bool repeatedSubstringPattern(string s) { // TODO 理解 next 数组的右移
    // NOTE: 加入 s 由 多个 a 串组成，即 s = aa...a
    // NOTE: 则 s + s == aa...aaa...a，必然出现 s (去除s的首尾避免找到原本的 s)
    // HACK: 反过来，如果 s + s 中出现了 s，则 s 一定由重复子串组成吗？
    // NOTE:
    auto str = (s + s).substr(1, s.size() * 2 - 2);
    return kmp(str, s);
  }

  bool kmp(string str, string &pattern) {
    // get next
    vector<int> next(pattern.size(), -1);
    for (int i = 1, j = -1; i < pattern.size(); i++) {
      while (j != -1 && pattern[j + 1] != pattern[i]) {
        j = next[j];
      }
      if (pattern[j + 1] == pattern[i]) {
        j++;
        next[i] = j;
      }
    }
    // match
    for (int i = 0, j = -1; i < str.size(); i++) {
      while (j != -1 && str[i] != pattern[j + 1]) {
        j = next[j];
      }
      if (str[i] == pattern[j + 1]) {
        j++;
      }
      if (j == pattern.size() - 1) {
        return true;
      }
    }
    return false;
  }
};
// @lc code=end
