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
    int maxPathSum(TreeNode* root, int& maxi){
        if(!root)
            return 0;

        int cand1 = max(0,maxPathSum(root->left, maxi));
        int cand2 = max(0,maxPathSum(root->right, maxi));
        maxi = max(maxi, cand1+cand2+root->val);

        return root->val + max(cand1, cand2);
    }
    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        maxPathSum(root, maxi);
        return maxi;
    }
};