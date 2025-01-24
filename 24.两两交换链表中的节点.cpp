// @before-stub-for-debug-begin
#include "commoncppproblem24.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=24 lang=cpp
 *
 * [24] 两两交换链表中的节点
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
  ListNode *swapPairs(ListNode *head) {
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *virtualHead = new ListNode{0, head}; // 加上哨兵节点
    ListNode *cur = head, *prev = virtualHead;
    head = head->next;
    while (cur != nullptr && cur->next != nullptr) {
      // HINT 交换 cur 和 cur->next
      prev->next = cur->next;
      cur->next = prev->next->next;
      prev->next->next = cur;
      prev = cur;
      cur = cur->next;
    }
    delete virtualHead;

    return head;
  }
};
// @lc code=end
