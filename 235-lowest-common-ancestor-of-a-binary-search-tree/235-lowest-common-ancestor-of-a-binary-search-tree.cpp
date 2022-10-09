/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode *LCA = root;
        TreeNode *cur = root;
        if(p->val > q->val) 
        {
            swap(p,q);
        }
        while(cur) 
        {
            if(cur == p || cur == q) 
            {
                LCA = cur;
                break;
            }
            if(p->val < cur->val && q->val > cur->val)
            {
                LCA = cur; 
                break;
            }
            if(p->val < cur->val && q->val < cur->val) 
            {
                cur = cur->left;
            }
            if(p->val > cur->val && q->val > cur->val) 
            {
                cur = cur->right;
            }
        }
        return LCA;
    }
};