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
  public TreeNode ConstructFromPrePost(int[] preorder, int[] postorder) {
    return ConstructFromPrePost(preorder, postorder, 0, preorder.Length - 1, 0, postorder.Length - 1);
  }

  private TreeNode ConstructFromPrePost(int[] preorder, int[] postorder, int preStart, int preEnd, int postStart, int postEnd) {
    if (preStart > preEnd) {
      return null;
    }
    TreeNode root = new TreeNode(preorder[preStart]);

    if (preStart == preEnd) {
      return root;
    }

    int leftRoot = preorder[preStart + 1];
    int leftRootIndex = Array.IndexOf(postorder, leftRoot);
    int leftCount = leftRootIndex - postStart + 1;

    root.left = ConstructFromPrePost(preorder, postorder, preStart + 1, preStart + leftCount, postStart, leftRootIndex);
    root.right = ConstructFromPrePost(preorder, postorder, preStart + leftCount + 1, preEnd, leftRootIndex + 1, postEnd - 1);
    
    return root;
  }
}