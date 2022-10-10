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
    
    
    void recoverTree(TreeNode* root) {
        TreeNode *cur = root;
        
        vector<int> inOrder;
        //Doing morris traversal for getting Inorder.
        while(cur) 
        {
            if(cur->left == NULL) 
            {
                inOrder.push_back(cur->val);
                cur = cur->right;
            }
            else
            {
                TreeNode *pred = cur->left;
                while(pred->right != NULL && pred->right != cur) 
                {
                    pred = pred->right;
                }
                if(pred->right == NULL) 
                {
                    pred->right = cur;
                    cur = cur->left;
                }
                else 
                {
                    pred->right = NULL; 
                    inOrder.push_back(cur->val);
                    cur = cur->right;
                }
            }
        }
        
        sort(inOrder.begin(),inOrder.end()); // Sorting to get correct BST.
        int ind = 0;
        cur = root;
        //again doing morris traversal for correcting BST.
        while(cur) 
        {
            if(cur->left == NULL) 
            {
                cur->val = inOrder[ind++];
                cur = cur->right;
            }
            else
            {
                TreeNode *pred = cur->left;
                while(pred->right != NULL && pred->right != cur) 
                {
                    pred = pred->right;
                }
                if(pred->right == NULL) 
                {
                    pred->right = cur;
                    cur = cur->left;
                }
                else 
                {
                    pred->right = NULL; 
                    cur->val = inOrder[ind++];
                    cur = cur->right;
                }
            }
        }
        
    }
};