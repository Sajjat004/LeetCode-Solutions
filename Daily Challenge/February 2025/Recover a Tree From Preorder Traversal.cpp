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
public:
  TreeNode* recoverFromPreorder(string traversal) {
    int index = 0;
    return recoverFromPreorder(traversal, index, 0);
  }

private:
  TreeNode* recoverFromPreorder(string traversal, int& index, int depth) {
    if (index >= traversal.size()) {
      return nullptr;
    }

    int currentDepth = 0;
    int tempIndex = index;
    while (index < traversal.size() && traversal[index] == '-') {
      currentDepth++;
      index++;
    }

    if (currentDepth != depth) {
      index = tempIndex;
      return nullptr;
    }

    int value = 0;
    while (index < traversal.size() && traversal[index] != '-') {
      value = value * 10 + (traversal[index] - '0');
      index++;
    }

    TreeNode* root = new TreeNode(value);
    root->left = recoverFromPreorder(traversal, index, depth + 1);
    root->right = recoverFromPreorder(traversal, index, depth + 1);

    return root;
  }
};