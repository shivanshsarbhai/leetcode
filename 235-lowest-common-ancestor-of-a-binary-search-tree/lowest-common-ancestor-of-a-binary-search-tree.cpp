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
        if(!root)
            return NULL;

        bool isBothSmall = p->val < root->val && q->val < root->val;
        bool isBothBig =  p->val > root->val && q->val > root->val;

        if(isBothSmall)
            return lowestCommonAncestor(root->left, p, q);
        
        if(isBothBig)
            return lowestCommonAncestor(root->right, p, q);
        
        return root;
    }
};