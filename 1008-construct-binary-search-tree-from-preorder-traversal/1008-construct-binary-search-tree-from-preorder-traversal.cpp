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
    TreeNode *solve(int &ind,int N,vector<int> preOrder,int upperBound) 
    {
        if(ind == N) 
            return NULL;
        if(preOrder[ind] > upperBound) 
            return NULL;
        TreeNode *root = new TreeNode(preOrder[ind]);
        ind++;
        root->left = solve(ind,N,preOrder,root->val);
        root->right = solve(ind,N,preOrder,upperBound);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int ind = 0;
        return solve(ind,preorder.size(),preorder,INT_MAX);
    }
};