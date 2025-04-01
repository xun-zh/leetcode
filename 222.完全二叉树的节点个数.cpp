/*
 * @lc app=leetcode.cn id=222 lang=cpp
 *
 * [222] 完全二叉树的节点个数
 */
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
  int countNodes(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    // NOTE: 针对完全二叉树的优化点, 如果向左左深度 == 向右深度 说明是满二叉树
    // NOTE: -> 2^n - 1 个
    int leftDepth = 0;
    int rightDepth = 0;
    TreeNode *left = root->left;
    TreeNode *right = root->right;
    while (left) {
      left = left->left;
      ++leftDepth;
    }
    while (right) {
      right = right->right;
      ++rightDepth;
    }
    if (leftDepth == rightDepth) {
      return (2 << leftDepth) - 1;
    }
    return countNodes(root->left) + countNodes(root->right) + 1;
  }
};
// @lc code=end
