/*
 * @lc app=leetcode.cn id=206 lang=cpp
 *
 * [206] 反转链表
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
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
  ListNode *reverseList(ListNode *head) { return reverseListIterate(head); }

  ListNode *reverseListIterate(ListNode *head) { // HINT: 迭代法
    ListNode *newHead = nullptr, *iter = head, *temp;
    while (iter != nullptr) {
      /* code */
      temp = iter->next;
      iter->next = newHead;
      newHead = iter;
      iter = temp;
    }
    return newHead;
  }

  // ListNode *reverseListRecurse(ListNode *head) {}
};
// @lc code=end
