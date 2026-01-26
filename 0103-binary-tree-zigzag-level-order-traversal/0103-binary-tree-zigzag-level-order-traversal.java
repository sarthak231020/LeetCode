/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Deque<TreeNode> q = new ArrayDeque<>();
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) 
            return ans;
        q.push(root);
        boolean lToR = true;

        while(!q.isEmpty()) 
        {
            int size = q.size();
            List<Integer> tempAns = new ArrayList<>(Collections.nCopies(size,0));
            for(int i=0;i<size;i++) 
            {
                int index = lToR ? i : size-i-1;
                TreeNode currNode = q.peek(); 
                tempAns.set(index,currNode.val);
                q.poll();
                if(currNode.left != null)
                    q.offer(currNode.left);
                if(currNode.right != null) 
                    q.offer(currNode.right);
                
            }
            lToR = !lToR;
            ans.add(tempAns);
        }

        return ans;
    }
}