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
    int getHeight(TreeNode* root){
        if(!root)   
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        return 1+max(getHeight(root->left), getHeight(root->right));
    }

    bool isBalanced(TreeNode* root) {
        if(!root)
            return true;
        
        int heightLeft = getHeight(root->left);
        int heightRight = getHeight(root->right);

        return isBalanced(root->left) && isBalanced(root->right) && abs(heightLeft - heightRight) <=1;
    }
};