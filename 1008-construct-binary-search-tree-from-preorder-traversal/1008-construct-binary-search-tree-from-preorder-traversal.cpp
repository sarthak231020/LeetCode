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
    
    TreeNode *solve(int preStart,int preEnd,int inStart,int inEnd,vector<int> inOrder,vector<int> preOrder,map<int,int> inMap)
    {
        if(preStart > preEnd || inStart > inEnd) 
        {
            return NULL;
        }
        
        TreeNode *root = new TreeNode(preOrder[preStart]);
        int rootInd = inMap[preOrder[preStart]];
        int left = rootInd-inStart;
        
        root->left = solve(preStart+1,preStart+left,inStart,inStart+left-1,inOrder,preOrder,inMap);
        root->right = solve(preStart+left+1,preEnd,inStart+left+1,inEnd,inOrder,preOrder,inMap);
        
        return root;
    }
    
    TreeNode* bstFromPreorder(vector<int>& preOrder) {
        vector<int> inOrder =  preOrder;
        
        sort(inOrder.begin(),inOrder.end());
        int N = preOrder.size();
        
        map<int,int> inMap;
        for(int i=0;i<N;i++) 
        {
            inMap[inOrder[i]] = i;
        }
        
        return solve(0,N-1,0,N-1,inOrder,preOrder,inMap);
        
    }
};