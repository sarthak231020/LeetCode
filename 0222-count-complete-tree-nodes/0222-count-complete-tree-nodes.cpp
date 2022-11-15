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
    // O(N) - Bruteforce Solution Using Inorder
//     void dfs(TreeNode *root,int &cnt)
//     {
//         if(root == NULL) 
//             return;
        
//         cnt++;
//         dfs(root->left,cnt);
//         dfs(root->right,cnt);
        
//     }
    
    int height(TreeNode *root,bool l) 
    {
        int cnt = 0;
        if(l)
        {
            while(root)
            {
                root = root->left;
                cnt++;
            }
        }
        else 
        {
            while(root)
            {
                root = root->right;
                cnt++;
            }
        }
        return cnt;
    }
    
    int dfs(TreeNode *root) 
    {
        if(root == NULL)
            return 0;
        
        int lh = height(root,true);
        int rh = height(root,false);
        if(lh == rh) 
        {
            return (1<<lh)-1;
        }
        return 1+dfs(root->left)+dfs(root->right);
    } 
    
    int countNodes(TreeNode* root) {
        
        return dfs(root);
        
    }
};