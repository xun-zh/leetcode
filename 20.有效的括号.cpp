/*
 * @lc app=leetcode.cn id=20 lang=cpp
 *
 * [20] 有效的括号
 */

// @lc code=start
class Solution {
public:
  bool isValid(string s) {
    stack<char> stack;
    stack.push(s[0]);
    for (size_t i = 1; i < s.size(); ++i) {
      if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
        stack.push(s[i]);
      } else {
        // 扫描到右括号
        if (stack.empty()) {
          return false;
        }
        if (s[i] == ')' && stack.top() != '(') {
          return false;
        } else if (s[i] == ']' && stack.top() != '[') {
          return false;
        } else if (s[i] == '}' && stack.top() != '{') {
          return false;
        } else {
          stack.pop();
        }
      }
    }
    if (stack.empty()) {
      return true;
    }
    return false;
  }
};
// @lc code=end
