/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */

#include <queue>

using namespace std;

// @lc code=start
class MyStack {
private:
  queue<int> q{};

public:
  MyStack() {
    // NOTE: 用一个队列实现栈
    // NOTE: 每次将出队的元素入队（自己做自己的备份）
  }

  void push(int x) { q.push(x); }

  int pop() {
    size_t size = q.size();
    for (size_t i = 0; i < size - 1; ++i) {
      q.push(q.front());
      q.pop();
    }
    int ret = q.front();
    q.pop();
    return ret;
  }

  int top() { return q.back(); }

  bool empty() { return q.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
// @lc code=end
