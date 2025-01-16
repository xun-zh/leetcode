/*
 * @lc app=leetcode.cn id=704 lang=cpp
 *
 * [704] 二分查找
 */

#include <vector>
// #include <iostream>

using namespace std;

// @lc code=start
class Solution {
public:
  int search(vector<int> &nums, int target) {
    int left = 0;
    int right = nums.size() - 1;
    // NOTE: <= 保证了 left == right 时也能继续查找，在个数为奇数时是有意义的
    while (left <= right) {
      int mid = left + (right - left) / 2; // HINT: 防止溢出
      if (nums[mid] == target) {
        return mid;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return -1;
  }
};
// @lc code=end
