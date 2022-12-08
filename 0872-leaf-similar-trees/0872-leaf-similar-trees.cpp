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
    void inOrder(TreeNode *root,vector<int> &ans) 
    {
        if(root == NULL) 
            return;
        
        inOrder(root->left,ans);
        if(root->left == NULL && root->right == NULL) 
            ans.push_back(root->val);
        inOrder(root->right,ans);
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> leaf1,leaf2;
        inOrder(root1,leaf1);
        inOrder(root2,leaf2);
        
        return leaf1 == leaf2;
    }
};