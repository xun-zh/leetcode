// @before-stub-for-debug-begin
#include "commoncppproblem438.h"
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @lc code=start
class Solution {
public:
  vector<int> findAnagrams_TOO_LANG_TIME(string s,
                                         string p) { // HACK: 击败 5% 的解法 😢
    // HINT 特殊情况
    if (s.size() < p.size()) {
      return {};
    }
    auto map_p = unordered_map<char, int>{};
    auto map_temp = unordered_map<char, int>{};

    auto res = vector<int>{};
    for (auto ch : p) {
      map_p[ch]++;
    }
    for (int i = 0; i <= s.size() - p.size(); i++) {
      map_temp.clear();
      for (int j = i; j < i + p.size(); j++) {
        map_temp[s[j]]++;
      }
      if (isEqualMap(map_p, map_temp)) {
        res.emplace_back(i);
      }
    }
    return res;
  }

  bool isEqualMap(unordered_map<char, int> &map1,
                  unordered_map<char, int> &map2) {
    if (map1.size() != map2.size()) {
      return false;
    }
    for (auto item_1 : map1) {
      if (item_1.second != map2[item_1.first]) {
        return false;
      }
    }
    return true;
  }

  vector<int> findAnagrams(string s, string p) { // HACK: 击败 5% 的解法 😢
    // HINT 特殊情况
    if (s.size() < p.size()) {
      return {};
    }
    auto res = vector<int>{};
    // NOTE: 数组当作hash表使用 加上滑动窗口
    auto p_map = vector<int>(26);
    auto s_map = vector<int>(26);
    // HINT: 先判断一次首位
    for (size_t i = 0; i < p.size(); i++) {
      ++s_map[s[i] - 'a'];
      ++p_map[p[i] - 'a'];
    }
    if (p_map == s_map) {
      res.emplace_back(0);
    }
    // NOTE: 开始窗口滑动，本质是统计词频，
    for (size_t i = 0; i < s.size() - p.size(); ++i) {
      --s_map[s[i] - 'a']; // NOTE: 移出窗口
      ++s_map[s[i + p.size()] - 'a'];
      if (s_map == p_map) {
        res.emplace_back(i + 1);
      }
    }
    return res;
  }
};
// @lc code=end
