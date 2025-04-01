/*
 * @lc app=leetcode.cn id=101 lang=cpp
 *
 * [101] 对称二叉树
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
  bool isSymmetric(TreeNode *root) { return recur(root->left, root->right); }

  bool recur(TreeNode *left, TreeNode *right) {
    if (left == nullptr && right == nullptr) {
      return true;
    } else if (left == nullptr || right == nullptr) {
      return false;
    }
    return (left->val == right->val) && recur(left->left, right->right) &&
           recur(left->right, right->left);
  }
  // TODO: 迭代法
};
// @lc code=end
