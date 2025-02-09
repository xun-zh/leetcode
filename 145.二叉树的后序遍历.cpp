/*
 * @lc app=leetcode.cn id=145 lang=cpp
 *
 * [145] 二叉树的后序遍历
 */
#include <vector>
using namespace std;
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
  vector<int> postorderTraversal_recur(TreeNode *root) {
    vector<int> res{};
    postOrder(root, res);
    return res;
  }

  void postOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    postOrder(root->left, res);
    postOrder(root->right, res);
    res.push_back(root->val);
  }
};
// @lc code=end
