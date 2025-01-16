// @before-stub-for-debug-begin
#include <list>
#include <string>
#include <vector>
using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};
// @before-stub-for-debug-end

/**
 * @lc app=leetcode.cn id=160 lang=cpp
 *
 * [160] 相交链表
 */

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
  /**
   * NOTE: 参考题解，借鉴链表判环的思想，视作追及问题
   * NOTE: 如果 A, B 有交点
   * NOTE: 如果 A, B 没有交点
   */
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode *a = headA, *b = headB;
    if (a == nullptr || b == nullptr) {
      return nullptr;
    }
    while (true) {
      a = a->next;
      b = b->next;
      if (a == nullptr && b == nullptr) { // HINT: 没有交点
        return nullptr;
      }
    }

    // while (a != nullptr) { // HINT: 暴力遍历, n^2
    //   b = headB;
    //   while (b != nullptr) {
    //     if (a == b) {
    //       return a;
    //     }
    //     b = b->next;
    //   }
    //   a = a->next;
    // }
    return nullptr;
  }
};
// @lc code=end
