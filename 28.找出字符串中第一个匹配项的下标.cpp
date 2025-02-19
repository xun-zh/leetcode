// @before-stub-for-debug-begin
#include "commoncppproblem28.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=28 lang=cpp
 *
 * [28] 找出字符串中第一个匹配项的下标
 */

// @lc code=start
class Solution {
public:
  int strStr(string haystack, string needle) {
    if (needle.size() == 0) {
      return 0;
    }
    // next
    vector<int> next(needle.size(), 0);
    // HINT: pre_tail: 指向前缀末尾，也是最长相等前后缀的长度
    // HINT: post_tail: 指向后缀末尾，post及post之前也指当前求的子串
    for (int post_tail = 1, pre_tail = 0; post_tail < needle.size();
         post_tail++) {
      while (pre_tail > 0 && needle[post_tail] != needle[pre_tail]) {
        // NOTE: 不相等时，说明前后缀不匹配了-> 前缀太长，
        // NOTE: 回溯到上一个最长相等前后缀的长度，再次比较
        pre_tail = next[pre_tail - 1];
      }
      if (needle[post_tail] == needle[pre_tail]) {
        pre_tail++;
      }
      next[post_tail] = pre_tail;
    }
    // match
    for (int i = 0, j = 0; i < haystack.size(); i++) {
      while (j > 0 && haystack[i] != needle[j]) {
        j = next[j - 1];
      }
      if (haystack[i] == needle[j]) {
        j++;
      }
      if (j == needle.size()) {
        return i - needle.size() + 1;
      }
    }
    return -1;
  }
};
// @lc code=end
