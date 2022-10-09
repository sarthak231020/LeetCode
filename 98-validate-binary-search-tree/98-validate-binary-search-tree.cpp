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
    bool solve(TreeNode *root,long long l,long long r) 
    {
        if(root == NULL) 
            return true;
        if(l >=(long long) root->val || r <= (long long) root->val) 
            return false;
        
        bool left = solve(root->left,l,(long long)root->val);
        bool right = solve(root->right,(long long)root->val,r);
        
       if(left == false || right == false) 
           return false;
        return true;
    }
    bool isValidBST(TreeNode* root) {
        long long l = LONG_MIN; 
        long long r = LONG_MAX;
        return solve(root,l,r);
    }
};