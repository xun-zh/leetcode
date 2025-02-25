/*
 * @lc app=leetcode.cn id=429 lang=cpp
 *
 * [429] N 叉树的层序遍历
 */

#include <queue>
#include <vector>
using namespace std;
// Definition for a Node.
class Node {
public:
  int val;
  vector<Node *> children;

  Node() {}

  Node(int _val) { val = _val; }

  Node(int _val, vector<Node *> _children) {
    val = _val;
    children = _children;
  }
};

// @lc code=start

class Solution {
public:
  vector<vector<int>> levelOrder(Node *root) {
    if (root == nullptr) {
      return {};
    }
    queue<Node *> q{};
    vector<vector<int>> res{};
    Node *temp;
    q.push(root);
    while (!q.empty()) {
      int level_size = q.size();
      vector<int> level{};
      while (level_size--) {
        temp = q.front();
        q.pop();
        level.emplace_back(temp->val);
        // HINT: next level
        for (auto node : temp->children) {
          q.push(node);
        }
      }
      res.push_back(level);
    }
    return res;
  }
};
// @lc code=end
