/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>

using namespace std;
// @lc code=start
class MyQueue {
private:
  stack<int> in{};
  stack<int> out{};

public:
  MyQueue() {
    /**
     * @brief
     * NOTE: in 用于输入，out 用于输出，当 out 为空时，将 in 的元素全部转移到
     * NOTE: out
     */
  }

  void push(int x) { in.push(x); }

  int pop() {
    if (out.empty()) {
      transfer();
    }
    int ret = out.top();
    out.pop();
    return ret;
  }

  int peek() {
    if (out.empty()) {
      transfer();
    }
    return out.top();
  }

  bool empty() { return in.empty() && out.empty(); }

  void transfer() {
    while (!in.empty()) {
      out.push(in.top());
      in.pop();
    }
  }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
