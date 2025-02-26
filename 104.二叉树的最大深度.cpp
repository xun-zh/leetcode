/*
 * @lc app=leetcode.cn id=104 lang=cpp
 *
 * [104] 二叉树的最大深度
 */
#include <algorithm>
#include <iostream>
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
class Solution { // HINT: recoursion
public:
  int maxDepth_recur(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    return std::max(maxDepth(root->left), maxDepth(root->right)) + 1;
  }

  int maxDepth(TreeNode *root) { // HINT: 迭代法使用 层次遍历
    if (root == nullptr) {
      return 0;
    }
    queue<TreeNode *> q{};
    vector<int> res{};
    q.push(root);
    int level = 0;
    TreeNode *temp_node = nullptr;
    while (!q.empty()) {
      int level_size = q.size(); // HINT: 这一层有 s 个元素
      int max = INT_MIN;
      ++level;
      while (level_size--) {
        temp_node = q.front();
        q.pop();
        if (temp_node->left) {
          q.push(temp_node->left);
        }
        if (temp_node->right) {
          q.push(temp_node->right);
        }
      }
    }
    return level;
  }
};
// @lc code=end
