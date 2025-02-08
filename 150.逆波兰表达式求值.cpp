// @before-stub-for-debug-begin
#include "commoncppproblem150.h"
#include <stack>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=150 lang=cpp
 *
 * [150] 逆波兰表达式求值
 */

// @lc code=start
class Solution {
public:
  int evalRPN(vector<string> &tokens) {
    stack<int> nums{};
    for (string &token : tokens) {
      if (token == "+" || token == "-" || token == "*" || token == "/") {
        int num2 = nums.top();
        nums.pop();
        int num1 = nums.top();
        nums.pop();
        switch (token[0]) {
        case '+':
          num1 += num2;
          break;
        case '-':
          num1 -= num2;
          break;
        case '*':
          num1 *= num2;
          break;
        case '/':
          num1 /= num2;
          break;
        default:
          break;
        }
        nums.push(num1);
      } else {
        nums.push(stoi(token));
      }
    }
    return nums.top();
  }
};
// @lc code=end
