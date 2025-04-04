/*
 * @lc app=leetcode.cn id=111 lang=cpp
 *
 * [111] 二叉树的最小深度
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
  int minDepth(TreeNode *root) {
    if (root == nullptr) {
      return 0;
    }
    // 链表的情况[2,null,3,null,4,null,5,null,6]
    // HINT: 当某个子树为空时其最小深度不能视作1
    /**
     *        1
     *         \
     *          2
     *         / \
     *        3   4
     *           / \
     */
    return recur(root);
  }

  int recur(TreeNode *node) {
    if (node == nullptr) {
      return 0;
    }
    int leftDepth = recur(node->left);
    int rightDepth = recur(node->right);
    if (leftDepth == 0) {
      return rightDepth + 1;
    }
    if (rightDepth == 0) {
      return leftDepth + 1;
    }
    return 1 + std::min(leftDepth, rightDepth);
  }
};
// @lc code=end
