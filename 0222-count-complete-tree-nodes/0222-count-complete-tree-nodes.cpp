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
     // Bruteforce Solution Using Inorder
    // TC - O(N) SC - O(logN)(Since Complete BT).
//     void dfs(TreeNode *root,int &cnt)
//     {
//         if(root == NULL) 
//             return;
        
//         cnt++;
//         dfs(root->left,cnt);
//         dfs(root->right,cnt);
        
//     }
    
    //Optimized Solution TC -> O((logN)^2)(since we are calculating height of left and height of right cubtree Takes O(logN) and at worst we are calculating it for logN nodes). SC->O(logN) 
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