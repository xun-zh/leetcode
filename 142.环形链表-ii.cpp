// @before-stub-for-debug-begin
#include "commoncppproblem142.h"
#include <string>
#include <vector>

using namespace std;
// @before-stub-for-debug-end

/*
 * @lc app=leetcode.cn id=142 lang=cpp
 *
 * [142] 环形链表 II
 */
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
};

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode *detectCycle(ListNode *head) {
    ListNode *fast = head, *slow = head;
    while (fast != nullptr && fast->next != nullptr) {
      slow = slow->next; // HACK ?
      fast = fast->next->next;
      // NOTE: 关键在于理解如果由环，这遍历永远不会停止
      // NOTE: 而且 fast slow 一定会相遇，追及问题
      if (fast == slow) {
        // NOTE: 找到环之后如何判断环的入口？
        // TODO
        slow = head;
        while (fast != slow) {
          slow = slow->next;
          fast = fast->next;
        }
        return slow;
      }
    }
    return nullptr;
  }
};
// @lc code=end
