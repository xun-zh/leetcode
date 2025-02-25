/*
 * @lc app=leetcode.cn id=116 lang=cpp
 *
 * [116] 填充每个节点的下一个右侧节点指针
 */

#include <queue>
#include <vector>
using namespace std;

// Definition for a Node.
class Node {
public:
  int val;
  Node *left;
  Node *right;
  Node *next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node *_left, Node *_right, Node *_next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

// @lc code=start

class Solution {
public:
  Node *connect(Node *root) {
    if (root == nullptr) {
      return {};
    }
    queue<Node *> q{};
    vector<int> res{};
    q.push(root);

    Node *temp_node = nullptr;
    Node *pre_node = nullptr;
    while (!q.empty()) {
      int level_size = q.size() - 1; // HINT: 这一层有 s 个元素
      pre_node = q.front();
      q.pop();
      if (pre_node->left) {
        q.push(pre_node->left);
      }
      if (pre_node->right) {
        q.push(pre_node->right);
      }
      while (level_size--) {
        temp_node = q.front();
        q.pop();
        pre_node->next = temp_node;
        pre_node = temp_node;
        if (temp_node->left) {
          q.push(temp_node->left);
        }
        if (temp_node->right) {
          q.push(temp_node->right);
        }
      }
    }
    return root;
  }
};
// @lc code=end
