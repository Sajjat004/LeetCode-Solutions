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
class FindElements {
  unordered_map<int, bool> exists;

  void dfs(TreeNode* node, int val) {
    if (node == nullptr) return;
    exists[val] = true;
    
    if (node->left != NULL) dfs(node->left, 2 * val + 1);
    if (node->right != NULL) dfs(node->right, 2 * val + 2);
  }

public:
  FindElements(TreeNode* root) {
    dfs(root, 0);
  }
  
  bool find(int target) {
    if (exists.find(target) != exists.end()) return true;
    return false;
  }
};

/**
* Your FindElements object will be instantiated and called as such:
* FindElements* obj = new FindElements(root);
* bool param_1 = obj->find(target);
*/