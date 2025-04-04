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
  TreeNode* lcaDeepestLeaves(TreeNode* root) {
    if (!root) return nullptr;
    auto [lca, _] = dfs(root, 0);
    return lca;
  }

private:
  pair<TreeNode*, int> dfs(TreeNode* node, int depth) {
    if (!node) return {nullptr, depth};
    auto [leftLCA, leftDepth] = dfs(node->left, depth + 1);
    auto [rightLCA, rightDepth] = dfs(node->right, depth + 1);
    if (leftDepth == rightDepth) return {node, leftDepth};
    return leftDepth > rightDepth ? make_pair(leftLCA, leftDepth) : make_pair(rightLCA, rightDepth);
  }
};