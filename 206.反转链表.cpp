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

  /**
   * NOTE: 总体思路即从倒数第二个节点开始
   * NOTE: 每次每次让下一个节点的 next 指向自己
   * NOTE: 自己的 next 可以不管，但这里指向 nullptr，是为了反转后的尾节点
   * NOTE: 这里递归借助函数调用栈，存储了前面的节点
   */
  ListNode *reverseListRecurse(ListNode *head) { // HINT: 递归法
    if (head == nullptr || head->next == nullptr) {
      return head;
    }
    ListNode *newHead = reverseListRecurse(head->next);
    head->next->next = head;
    head->next = nullptr;
    return newHead;
  }
};
// @lc code=end
