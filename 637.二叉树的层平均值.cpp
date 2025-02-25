/*
 * @lc app=leetcode.cn id=637 lang=cpp
 *
 * [637] 二叉树的层平均值
 */

#include <queue>
#include <vector>

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
  /**
   * @brief
   * NOTE: 层次遍历
   */
  vector<double> averageOfLevels(TreeNode *root) {
    queue<TreeNode *> q{};
    vector<double> res{};
    TreeNode *temp;
    q.push(root);
    while (!q.empty()) {
      int level_size = q.size();
      double sum = 0;
      for (int _ = 0; _ < level_size; ++_) {
        temp = q.front();
        q.pop();
        sum += temp->val;
        if (temp->left) {
          q.push(temp->left);
        }
        if (temp->right) {
          q.push(temp->right);
        }
      }
      res.emplace_back(static_cast<double>(sum) / level_size);
    }
    return res;
  }
};
// @lc code=end
