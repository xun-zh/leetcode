/*
 * @lc app=leetcode.cn id=199 lang=cpp
 *
 * [199] 二叉树的右视图
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
   *
   * @param root
   * @return vector<int>
   * NOTE: 分析一下可知，二叉树每层最后一个即是结果
   */
  vector<int> rightSideView(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    queue<TreeNode *> q{};
    vector<int> res{};
    TreeNode *temp;
    q.push(root);
    while (!q.empty()) {
      int level_size = q.size();
      for (int _ = 1; _ < level_size; ++_) {
        temp = q.front();
        if (temp->left) {
          q.push(temp->left);
        }
        if (temp->right) {
          q.push(temp->right);
        }
        q.pop();
      }
      temp = q.front();
      if (temp->left) {
        q.push(temp->left);
      }
      if (temp->right) {
        q.push(temp->right);
      }
      res.emplace_back(temp->val);
      q.pop();
      /* code */
    }
    return res;
  }
};
// @lc code=end
