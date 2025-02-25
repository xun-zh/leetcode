/*
 * @lc app=leetcode.cn id=515 lang=cpp
 *
 * [515] 在每个树行中找最大值
 */

#include <queue>
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
  vector<int> largestValues(TreeNode *root) {
    if (root == nullptr) {
      return {};
    }
    queue<TreeNode *> q{};
    vector<int> res{};
    q.push(root);

    TreeNode *temp_node = nullptr;
    while (!q.empty()) {
      int level_size = q.size(); // HINT: 这一层有 s 个元素
      int max = INT_MIN;
      while (level_size--) {
        temp_node = q.front();
        q.pop();
        if (max < temp_node->val) {
          max = temp_node->val;
        }
        if (temp_node->left) {
          q.push(temp_node->left);
        }
        if (temp_node->right) {
          q.push(temp_node->right);
        }
      }
      res.emplace_back(max);
    }
    return res;
  }
};
// @lc code=end
