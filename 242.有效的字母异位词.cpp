/*
 * @lc app=leetcode.cn id=242 lang=cpp
 *
 * [242] 有效的字母异位词
 */

#include <string>
#include <unordered_map>
using namespace std;

// @lc code=start
class Solution {
public:
  bool isAnagram(string s, string t) {
    auto map_s = unordered_map<char, int>{};
    auto map_t = unordered_map<char, int>{};
    for (auto ch : s) {
      map_s[ch]++;
    }
    for (auto ch : t) {
      map_t[ch]++;
    }
    // HINT: 两个map大小不同一定不对
    if (map_s.size() != map_t.size()) {
      return false;
    }
    for (auto item_s : map_s) {
      if (item_s.second != map_t[item_s.first]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
