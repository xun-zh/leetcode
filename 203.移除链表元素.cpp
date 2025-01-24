// @before-stub-for-debug-begin
#include <string>
#include <vector>

// #include "commoncppproblem203.h"

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=203 lang=cpp
 *
 * [203] 移除链表元素
 */

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
  ListNode *removeElements(ListNode *head, int val) {
    if (head == nullptr) {
      return head;
    }
    ListNode *cur = head;
    ListNode *temp;
    // HINT: 因为链表删除需要前一个节点
    // HINT: 从第二个开始，最后单独判断第一个节点是否要删除
    while (cur != nullptr && cur->next != nullptr) {
      if (cur->next->val == val) {
        temp = cur->next;
        cur->next = cur->next->next;
        delete temp;
      } else {
        // HINT: 要删除地是下一个节点，不删除时前进，删除了原地不动
        cur = cur->next;
      }
    }
    if (head->val == val) {
      temp = head;
      head = head->next;
      delete temp;
    }
    return head;
  }
};
// @lc code=end
