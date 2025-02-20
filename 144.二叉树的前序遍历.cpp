// @before-stub-for-debug-begin
#include "commoncppproblem144.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=144 lang=cpp
 *
 * [144] 二叉树的前序遍历
 */
#include <stack>
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
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res{};
    stack<TreeNode *> temp_stack{};
    if (root == nullptr)
      return {};
    temp_stack.push(root);
    TreeNode *v = nullptr;
    while (!temp_stack.empty()) {
      v = temp_stack.top();
      temp_stack.pop();
      res.push_back(v->val);
      if (v->right) {
        temp_stack.push(v->right);
      }
      if (v->left) {
        temp_stack.push(v->left);
      }
    }

    return res;
  }
  vector<int> preorderTraversal_recur(TreeNode *root) {
    vector<int> res{};
    preOrder(root, res);
    return res;
  }

  void preOrder(TreeNode *root, vector<int> &res) {
    if (root == nullptr) {
      return;
    }
    res.push_back(root->val);
    preOrder(root->left, res);
    preOrder(root->right, res);
  }
};
// @lc code=end
