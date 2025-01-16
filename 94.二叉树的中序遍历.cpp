// @before-stub-for-debug-begin
#include <string>
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

// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=94 lang=cpp
 *
 * [94] 二叉树的中序遍历
 */

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
  vector<int> inorderTraversal_recur(TreeNode *root) { // HINT: 递归解法
    vector<int> res{};
    recur(root, res);
    return res;
  }

  void recur(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    recur(root->left, res);
    res.push_back(root->val);
    recur(root->right, res);
  }

  vector<int> inorderTraversal(TreeNode *root) { // TODO: 迭代解法
  }
};
// @lc code=end
