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
    
    bool solve(TreeNode *p,TreeNode *q) 
    {
        if(p == NULL && q == NULL) 
            return true; 
        if(p == NULL) 
            return false; 
        if(q == NULL) 
            return false;
        
        return (p->val)==(q->val) && solve(p->left,q->left) && solve(p->right,q->right);
    }
//     void solve(TreeNode *root,vector<int> &ans) 
//     {
//         if(root == NULL) 
//             return;
//         ans.push_back(root->val);
        
//         solve(root->left,ans);
//         solve(root->right,ans);
//     }
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
//         vector<int> v1,v2;
        
//         solve(p,v1);
//         solve(q,v2);
        
//         return v1 == v2; 
        
        return solve(p,q);
        
    }
};