/*
 * @lc app=leetcode.cn id=234 lang=cpp
 *
 * [234] 回文链表
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
  /**
   * NOTE:
   * HINT: 先尝试了转换为数字，不出所料超时了
   */
  bool isPalindrome(ListNode *head) { // TODO
    int seqNum = 0, reNum = 0, weight = 1;
    ListNode *iter = head;
    while (iter != nullptr) {
      /* code */
      seqNum = seqNum * 10 + iter->val;
      reNum = reNum + iter->val * weight;
      weight *= 10;
      iter = iter->next;
    }
    return seqNum == reNum;
  }
};
// @lc code=end
