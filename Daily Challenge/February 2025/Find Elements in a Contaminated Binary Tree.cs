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
 public class FindElements {
  private Dictionary<int, bool> _exists;

  public FindElements(TreeNode root) {
    _exists = new Dictionary<int, bool>();
    Dfs(root, 0);
  }
  
  public bool Find(int target) {
    if (_exists.ContainsKey(target)) return true;
    return false;
  }

  private void Dfs(TreeNode node, int val) {
    if (node == null) return;
    _exists.Add(val, true);
    
    Dfs(node.left, 2 * val + 1);
    Dfs(node.right, 2 * val + 2);
  }
}

/**
* Your FindElements object will be instantiated and called as such:
* FindElements obj = new FindElements(root);
* bool param_1 = obj.Find(target);
*/