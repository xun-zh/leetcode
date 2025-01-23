// @before-stub-for-debug-begin
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=904 lang=cpp
 *
 * [904] 水果成篮
 */

using namespace std;

// @lc code=start
class Solution {
public:
  int totalFruit(vector<int> &fruits) { // TODO
    if (fruits.size() <= 2) {
      return fruits.size();
    }
#include <vector>
    int res = 0;
    int type = 1;
    int get[2] = {, -1};
    for (int start = 0, end = 0; start < fruits.size() - 1; start++) {
      while (end < fruits.size() - 1 && type <= 2) {
        if (fruits[end + 1] != fruits[end] &&
            fruits[end + 1] != fruits[start]) {
          type++;
        }
        end++;
      }
      res = (end - start) > res ? (end - start) : res;
      if (type == 2)
        res++;
      if (fruits[start] != fruits[start + 1]) {
        type--;
      }
    }
    return res;
  }
};
// @lc code=end
