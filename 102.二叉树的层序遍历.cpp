// @before-stub-for-debug-begin
#include "commoncppproblem102.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=102 lang=cpp
 *
 * [102] 二叉树的层序遍历
 */

#include <queue>
#include <vector>

using namespace std;

// struct TreeNode {
//   int val;
//   TreeNode *left;
//   TreeNode *right;
//   TreeNode() : val(0), left(nullptr), right(nullptr) {}
//   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//   TreeNode(int x, TreeNode *left, TreeNode *right)
//       : val(x), left(left), right(right) {}
// };

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
class Solution { // TODO
public:
  vector<vector<int>> levelOrder(TreeNode *root) {
    queue<TreeNode *> q{};
    vector<vector<int>> res{};
    q.push(root);
    if (root == nullptr) {
      return {};
    }
    TreeNode *temp_node = nullptr;
    while (!q.empty()) {
      int s = q.size(); // HINT: 这一层有 s 个元素
      vector<int> temp(s);
      for (int _ = 0; _ < s; _++) { // HINT: 遍历一层
        temp_node = q.front();
        q.pop();
        temp[_] = temp_node->val;
        if (temp_node->left) {
          q.push(temp_node->left);
        }
        if (temp_node->right) {
          q.push(temp_node->right);
        }
      }
      res.push_back(temp);
    }
    return res;
  }
};
// @lc code=end
