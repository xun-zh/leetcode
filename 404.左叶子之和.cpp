/*
 * @lc app=leetcode.cn id=404 lang=cpp
 *
 * [404] 左叶子之和
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
  int sumOfLeftLeaves(TreeNode *root) {
    int sumOfLeftLeaves = 0;
    recur(root, sumOfLeftLeaves);
    return sumOfLeftLeaves;
  }

  void recur(TreeNode *node, int &sum_) {
    if (node == nullptr) {
      return;
    }
    if (node->left == nullptr && node->right == nullptr) {
      return;
    }
    if (node->left != nullptr && node->left->left == nullptr &&
        node->left->right == nullptr) {
      sum_ += node->left->val;
    } else {
      recur(node->left, sum_);
    }
    recur(node->right, sum_);
  }
};
// @lc code=end
