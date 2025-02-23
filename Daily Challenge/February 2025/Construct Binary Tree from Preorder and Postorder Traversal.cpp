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
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
      return constructFromPrePost(preorder, postorder, 0, preorder.size() - 1, 0, postorder.size() - 1);
    }

  private:
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder, int preStart, int preEnd, int postStart, int postEnd) {
      if (preStart > preEnd) {
        return nullptr;
      }

      TreeNode* root = new TreeNode(preorder[preStart]);

      if (preStart == preEnd) {
        return root;
      }

      int leftRoot = preorder[preStart + 1];
      int leftRootIndex = -1;
      for (int i = postStart; i < postEnd; i++) {
        if (postorder[i] == leftRoot) {
          leftRootIndex = i;
          break;
        }
      }

      int leftSize = leftRootIndex - postStart + 1;

      root->left = constructFromPrePost(preorder, postorder, preStart + 1, preStart + leftSize, postStart, leftRootIndex);
      root->right = constructFromPrePost(preorder, postorder, preStart + leftSize + 1, preEnd, leftRootIndex + 1, postEnd - 1);

      return root;
    }
  };