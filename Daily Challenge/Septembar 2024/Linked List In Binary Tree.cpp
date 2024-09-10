// Challange Date: 07 Sep, 2024
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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
  bool dfs(TreeNode* root, ListNode* head) {
    if (root->val != head->val) return false;
    if (head->next == NULL) return true;

    bool ans = false;
    if (root->left != NULL) {
      ans |= dfs(root->left, head->next);
    }
    if (root->right != NULL) {
      ans |= dfs(root->right, head->next);
    }

    return ans;
  }

public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (root == NULL) return false;
    if (head == NULL) return true;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
      TreeNode* r = q.front();
      q.pop();

      cout << r << endl;

      if (dfs(r, head)) return true;
      
      TreeNode* left = r->left;
      TreeNode* right = r->right;

      if (left != NULL) q.push(left);
      if (right != NULL) q.push(right);
    }

    return false;
  }
};