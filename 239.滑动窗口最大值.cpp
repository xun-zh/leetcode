// @before-stub-for-debug-begin
#include "commoncppproblem239.h"
#include <deque>
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */

// @lc code=start
class Solution { // TODO

  class MonotonicQueue {
  private:
    deque<int> data;

  public:
    /**
     * @brief
     * @param v
     * NOTE: 窗口右移时，移入的元素一定是在窗口内的，那么此时队列中比他小的元素
     * NOTE: 均不可能是窗口内最大值，清理掉
     */
    void push(int v) {
      while (!data.empty() && v > data.back()) {
        data.pop_back();
      }
      data.push_back(v);
    }

    /**
     * @brief
     *
     * @param v
     * NOTE: 窗口右移时，移出的元素如果与队首的元素相等才 pop
     * NOTE: 因为队首一定是窗口内的最大值，
     * NOTE: 如果移出的元素不是队首元素说明最大值仍在窗口内，不 pop 也行
     */
    void pop(int v) {
      if (!data.empty() && v == data.front()) {
        data.pop_front();
      }
    }

    /**
     * @brief 返回 data 中的首元素，也是最大值，data 是有序的
     * @return int
     */
    int front() { return data.front(); }
  };

public:
  /**
   * @brief
   *
   * @param nums
   * @param k
   * @return vector<int>
   * NOTE: 使用单调队列：此队列内的值是窗口内的值，且可得到队列内最大值
   * NOTE: push pop 用于滑动窗口，front 返回最大值
   * NOTE: 队列中可以不维护窗口内的所有值，而是确保有最大值即可
   */
  vector<int> maxSlidingWindow(vector<int> &nums, int k) {
    vector<int> res(nums.size() - k + 1);
    MonotonicQueue q{};
    for (size_t i = 0; i < k - 1; i++) {
      q.push(nums[i]);
    }
    for (int i = k - 1; i < nums.size(); i++) {
      q.push(nums[i]);
      res[i - k + 1] = q.front();
      q.pop(nums[i - k + 1]);
    }
    return res;
  }
};
// @lc code=end
