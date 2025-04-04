/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     public int val;
 *     public TreeNode left;
 *     public TreeNode right;
 *     public TreeNode(int val=0, TreeNode left=null, TreeNode right=null) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
public class Solution {
  public TreeNode LcaDeepestLeaves(TreeNode root) {
    if (root == null) return null;
    
    var (depth, lca) = Dfs(root);
    
    return lca;
  }

  private (int, TreeNode) Dfs(TreeNode node) {
    if (node == null) return (0, null);
    
    var (leftDepth, leftLca) = Dfs(node.left);
    var (rightDepth, rightLca) = Dfs(node.right);
    
    if (leftDepth == rightDepth) return (leftDepth + 1, node);
    
    return leftDepth > rightDepth ? (leftDepth + 1, leftLca) : (rightDepth + 1, rightLca);
  }
}