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
    TreeNode *prev = NULL;
    TreeNode *firstViolation = NULL,*secViolation = NULL,*startViolation = NULL;
    void solve(TreeNode *root) 
    {
        if(root == NULL) 
        {
            return;
        }
        
        solve(root->left);
        
        if(firstViolation == NULL && prev != NULL && prev->val > root->val) 
        {
            startViolation = prev;
            firstViolation = root;
            // cout<<"start:"<<startViolation->val<<" first:"<<firstViolation->val<<endl;
        }
        if(firstViolation != NULL && firstViolation->val > root->val) 
        {
            secViolation = root;
            // cout<<" second:"<<secViolation->val<<endl;
        }
        
        prev = root;
        solve(root->right);
        
    }
    
    void swap(int *x,int *y) 
    {
        int temp = *x;
        *x = *y;
        *y = temp;
        
    }
    
    void recoverTree(TreeNode* root) {
        
        solve(root);
        // cout<<"start:"<<startViolation->val<<" first:"<<firstViolation->val<<" "<<endl;
        // if(secViolation != NULL)    
            // cout<<"Second: "<<secViolation->val<<endl;
        if(secViolation) 
        {
            swap(&startViolation->val,&secViolation->val);
        }
        else
        {
            swap(&startViolation->val,&firstViolation->val);
        }
           
    }
};