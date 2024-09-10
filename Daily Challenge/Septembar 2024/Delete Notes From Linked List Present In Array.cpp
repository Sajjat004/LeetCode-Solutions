// Challenge Date: 06 Sep, 2024
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
  ListNode* headNode = NULL;
  void addNode(ListNode* cur, int value) {
    if (cur == NULL) {
      ListNode* newNode = new ListNode(value);
      headNode = newNode;
      cur = headNode;
    } else {
      ListNode* newNode = new ListNode(value);
      cur->next = newNode;
      cur = cur->next;
    }
  }

  bool haveNum(vector<int>& nums, int n) {
    int l = 0, r = nums.size() - 1;

    while (l <= r) {
      int mid = (l + r) >> 1;
      if (nums[mid] < n) l = mid + 1;
      else if (nums[mid] > n) r = mid - 1;
      else return true;
    }

    return false;
  }
public:
  ListNode* modifiedList(vector<int>& nums, ListNode* head) {
    sort(nums.begin(), nums.end());

    ListNode* cur = NULL;
    while (head != NULL) {
      int value = head->val;
      if (haveNum(nums, value)) {
        addNode(cur, value);
      }
    }

    return headNode;
  }
};