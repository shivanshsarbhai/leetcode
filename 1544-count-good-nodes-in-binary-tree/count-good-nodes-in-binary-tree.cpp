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
    void countNodes(TreeNode* root, int maxTillNow, int &ans){
        if(!root)
            return;
        
        if(root->val >= maxTillNow)
            ans++;
        
        maxTillNow = max(root->val, maxTillNow);
        countNodes(root->left, maxTillNow, ans);
        countNodes(root->right, maxTillNow, ans);
    }

    int goodNodes(TreeNode* root) {
        if(!root)
            return 0;
        
        if(!root->left && !root->right)
            return 1;
        
        int ans = 1;
        countNodes(root->left, root->val, ans);
        countNodes(root->right, root->val, ans);
        return ans;
    }
};