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
    TreeNode* build(
        vector<int>&preorder, int preLeft, int preRight,
        vector<int>&inorder, int inLeft, int inRight,
        unordered_map<int,int>&mp
    ){
        if(preLeft <= preRight && inLeft <= inRight){
            TreeNode* root = new TreeNode(preorder[preLeft]);
            int inIndex = mp[root->val];
            int numEleInLeft = inIndex - inLeft;

            root->left = build(
                preorder, preLeft+1, preLeft+numEleInLeft, 
                inorder, inLeft, inIndex, mp
            );

            root->right = build(
                preorder, preLeft+numEleInLeft+1, preRight,
                inorder, inIndex+1, inRight, mp
            );

            return root;
        }

        return NULL;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mp;
        for(int i=0;i<inorder.size();i++)
            mp[inorder[i]]= i;

        return 
        build(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, mp);
    }
};