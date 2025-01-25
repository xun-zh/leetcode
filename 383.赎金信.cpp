/*
 * @lc app=leetcode.cn id=383 lang=cpp
 *
 * [383] 赎金信
 */

#include <string>
#include <unordered_map>

using namespace std;

// @lc code=start
class Solution {
public:
  bool canConstruct(string ransomNote, string magazine) {
    auto map_r = unordered_map<char, int>{};
    auto map_m = unordered_map<char, int>{};
    for (auto ch : ransomNote) {
      map_r[ch]++;
    }
    for (auto ch : magazine) {
      map_m[ch]++;
    }
    for (auto item_r : map_r) {
      if (item_r.second > map_m[item_r.first]) {
        return false;
      }
    }
    return true;
  }
};
// @lc code=end
