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

class BSTIterator {
public:
    stack<TreeNode *> st;
    bool reverse; //reverse holds true if it next() otherwise false.
    
    BSTIterator(TreeNode* root,bool rev) {    
        reverse = rev;
        pushAll(root);
        
    }
    
    int next() {
        TreeNode *node = st.top();
        st.pop();
        if(reverse == true)
            pushAll(node->right);
        else 
            pushAll(node->left);
        return node->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
    
    void pushAll(TreeNode *node) 
    {
        while(node) 
        {
            st.push(node);
            
            if(reverse == true)
                node = node->left;
            else 
                node = node->right;
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator nextImp(root,true),beforeImp(root,false);
        
        int i = nextImp.next();
        int j = beforeImp.next();
        
        while(i != j) 
        {
            if(i + j == k) 
                return true;
            else if(i+j < k) 
                i = nextImp.next();
            else 
                j = beforeImp.next();
        }
        return false;
    }
};