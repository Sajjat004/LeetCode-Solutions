// Challenge Date: 09 Sep, 2024
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
  ListNode*  setMatrix(int x1, int x2, int y1, int y2, vector<vector<int>>& matrix, ListNode* head) {
    // up side assign
    for (int j = y1; j <= y2; ++j) {
      if (head == NULL) return head;
      matrix[x1][j] = head->val;
      head = head->next;
    }
    // right side assign
    for (int i = x1 + 1; i < x2; ++i) {
      if (head == NULL) return head;
      matrix[i][y2] = head->val;
      head = head->next;
    }
    // dowun side assign
    for (int j = y2; j >= y1; --j) {
      if (head == NULL) return head;
      matrix[x2][j] = head->val;
      head = head->next;
    }
    // left side assign
    for (int i = x2 - 1; i > x1; --i) {
      if (head == NULL) return head;
      matrix[i][y1] = head->val;
      head = head->next;
    }

    return head;
  }

public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
      vector<vector<int>> matrix(m, vector<int>(n, -1));

      int x1 = 0, x2 = m - 1;
      int y1 = 0, y2 = n - 1;

      while (x1 <= x2 and y1 <= y2) {
        head = setMatrix(x1, x2, y1, y2, matrix, head);
        x1 += 1;
        x2 -= 1;
        y1 += 1;
        y2 -= 1;

      }

      return matrix;
    }
};