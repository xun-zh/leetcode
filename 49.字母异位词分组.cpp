// @before-stub-for-debug-begin
#include <algorithm>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=49 lang=cpp
 *
 * [49] 字母异位词分组
 */

// @lc code=start
class Solution {
public:
  // NOTE: 将每个单词排序，排序后组成字母相同的单词一定有同样的序列
  // NOTE: 另一种思路是统计每个单词26个字母的频率
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    unordered_map<string, vector<string>> str2strs; // hash
    for (auto str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      str2strs[key].push_back(str);
    }
    vector<vector<string>> res{};
    for (auto str2str : str2strs) {
      res.emplace_back(str2str.second);
    }
    return res;
  }
};
// @lc code=end
