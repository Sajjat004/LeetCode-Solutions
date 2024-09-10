// Challenge Date: 10 Sep, 2024
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
  ListNode* insertGreatestCommonDivisors(ListNode* head) {
    ListNode* cur = head;

    while (cur->next != NULL) {
      int a = cur->val;
      int b = cur->next->val;
      int g = __gcd(a, b);

      ListNode* newNode = new ListNode(g);
      newNode->next = cur->next;
      cur->next = newNode;
      cur = cur->next->next;
    }

    return head;
  }
};