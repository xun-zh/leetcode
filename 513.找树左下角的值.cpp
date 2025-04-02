/*
 * @lc app=leetcode.cn id=513 lang=cpp
 *
 * [513] 找树左下角的值
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
  /**
   * @brief
   * NOTE: 用层次遍历很简单，记录最后一行第一个元素即可。
   * NOTE: 这里用递归求解
   * @param root
   * @return int
   */
  int findBottomLeftValue(TreeNode *root) {
    int maxDepth = -1;
    int res = 0;
    recur(root, 0, maxDepth, res);
    return res;
  }

  void recur(TreeNode *node, int depth, int &maxDepth, int &res) {
    if (node == nullptr) {
      return;
    }
    if (depth > maxDepth) {
      maxDepth = depth;
      res = node->val;
    }
    recur(node->left, depth + 1, maxDepth, res);
    recur(node->right, depth + 1, maxDepth, res);
  }
};
// @lc code=end
