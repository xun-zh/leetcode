/*
 * @lc app=leetcode.cn id=257 lang=cpp
 *
 * [257] 二叉树的所有路径
 */

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
  vector<string> binaryTreePaths(TreeNode *root) {
    vector<string> res{};
    string path = "";
    recur(root, res, path);
    return res;
  }

  void recur(TreeNode *node, vector<string> &res, string path) {
    path += to_string(node->val);
    if (node->left == nullptr && node->right == nullptr) {
      res.emplace_back(path);
      return;
    }
    path += "->";
    if (node->left) {
      recur(node->left, res, path);
    }

    if (node->right) {
      recur(node->right, res, path);
    }
  }
};
// @lc code=end
