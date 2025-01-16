/*
 * @lc app=leetcode.cn id=34 lang=cpp
 *
 * [34] 在排序数组中查找元素的第一个和最后一个位置
 */

#include <vector>

using namespace std;

// @lc code=start
class Solution {
public:
  vector<int> searchRange(vector<int> &nums, int target) {
    vector<int> res{-1, -1};
    if (nums.empty()) {
      return res;
    }
    int left = 0, right = nums.size() - 1;
    // HINT: 二分查找
    while (left <= right) {
      int mid = left + (right - left) / 2;
      if (nums[mid] == target) {
        // HINT: 找到了 target，继续向左右查找
        int l = mid, r = mid;
        while (l >= 0 && nums[l] == target) {
          --l;
        }
        while (r < nums.size() && nums[r] == target) {
          ++r;
        }
        res[0] = l + 1; // HINT: l / r 都是不符合条件的，分别加减1
        res[1] = r - 1;
        return res;
      } else if (nums[mid] < target) {
        left = mid + 1;
      } else {
        right = mid - 1;
      }
    }
    return res;
  }
};
// @lc code=end
