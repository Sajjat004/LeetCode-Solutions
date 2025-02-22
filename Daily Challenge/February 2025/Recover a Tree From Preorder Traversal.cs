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
  public TreeNode RecoverFromPreorder(string traversal) {
    int index = 0;
    return RecoverFromPreorder(traversal, ref index, 0);
  }

  private TreeNode RecoverFromPreorder(string traversal, ref int index, int depth) {
    if (index >= traversal.Length) return null;
    int currentDepth = 0;
    while (index < traversal.Length && traversal[index] == '-') {
      currentDepth++;
      index++;
    }
    if (currentDepth != depth) {
      index -= currentDepth;
      return null;
    }
    int val = 0;
    while (index < traversal.Length && traversal[index] != '-') {
      val = val * 10 + (traversal[index] - '0');
      index++;
    }
    TreeNode node = new TreeNode(val);
    node.left = RecoverFromPreorder(traversal, ref index, depth + 1);
    node.right = RecoverFromPreorder(traversal, ref index, depth + 1);
    return node;
  }
}