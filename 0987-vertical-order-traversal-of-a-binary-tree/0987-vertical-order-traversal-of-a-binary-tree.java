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

class Triplet
{
    TreeNode node;
    int row, col;

    Triplet(TreeNode node,int row,int col) 
    {
        this.node = node;
        this.row = row;
        this.col = col;
    }

    public TreeNode getNode() 
    {
        return this.node;
    }

    public int getRow() 
    {
        return this.row;
    }
    
    public int getCol() 
    {
        return this.col;
    }
    
}

class Solution {
    public List<List<Integer>> verticalTraversal(TreeNode root) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) 
            return ans;
        Deque<Triplet> q = new ArrayDeque<>();
        Map<Integer,Map<Integer,PriorityQueue<Integer>>> ds = new TreeMap<>();
        q.offer(new Triplet(root,0,0));

        while(!q.isEmpty()) 
        {
            Triplet t = q.peek();
            q.poll();
            int row = t.getRow();
            int col = t.getCol();
            TreeNode node = t.getNode();
            ds.computeIfAbsent(col,k -> new TreeMap<>()).computeIfAbsent(row,k -> new PriorityQueue<>()).offer(node.val);
            if(node.left != null) 
                q.offer(new Triplet(node.left,row+1,col-1));
            if(node.right != null) 
                q.offer(new Triplet(node.right,row+1,col+1));
            
        }

        System.out.println(ds);
        
        ds.forEach((k,v)->{
            List<Integer> l = new ArrayList<>();
            v.forEach((k1,v1) -> {
                while(!v1.isEmpty())
                {
                    l.add(v1.peek());
                    v1.poll();
                }
            });
            ans.add(l);
        });
        return ans;
    }
}