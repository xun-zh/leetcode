// @before-stub-for-debug-begin
#include "commoncppproblem19.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=19 lang=cpp
 *
 * [19] 删除链表的倒数第 N 个结点
 */

// struct ListNode {
//   int val;
//   ListNode *next;
//   ListNode() : val(0), next(nullptr) {}
//   ListNode(int x) : val(x), next(nullptr) {}
//   ListNode(int x, ListNode *next) : val(x), next(next) {}
// };

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode *removeNthFromEnd(ListNode *head, int n) {
    ListNode *virtualHead = new ListNode{0, head};
    ListNode *fast = virtualHead, *slow = virtualHead;
    for (int i = 0; i < n; ++i) {
      fast = fast->next;
    }
    while (fast->next != nullptr) {
      fast = fast->next;
      slow = slow->next;
    }
    // HINT: 删除slow后的元素
    fast = slow->next;
    slow->next = slow->next->next;
    delete fast;
    // NOTE: [1]\n1，这种例子下，
    // NOTE: 真正的head时哨兵节点的下一个，head可能被delete了
    head = virtualHead->next;
    delete virtualHead;
    return head;
  }
};
// @lc code=end
