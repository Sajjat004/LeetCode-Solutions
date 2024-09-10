// Challenge Date: 08 Sep, 2024
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
  int countNode(ListNode* head) {
    int cnt = 0;
    while (head != NULL) {
      cnt++;
      head = head->next;
    }

    return cnt;
  }
public:
  vector<ListNode*> splitListToParts(ListNode* head, int k) {
    int n = countNode(head);
    int splitSize = n / k;
    n %= k;

    vector<ListNode*> ans;

    for (int i = 0; i < k; ++i) {
      ans.push_back(head);
      int s = splitSize;
      if (n) {
        s++;
        n--;
      }

      ListNode* last = NULL;
      while (s > 0 and head != NULL) {
        last = head;
        head = head->next;
        s--;
      }

      if (last != NULL) last->next = NULL;
    }

    return ans;
  }
};