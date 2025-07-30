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

    vector<int> getInorder(TreeNode* root){
        vector<int>inorder;
        TreeNode* curr = root;
        stack<TreeNode*>s;
        
        while(curr || !s.empty()){
            while(curr){
                s.push(curr);
                curr = curr->left;
            }

            curr = s.top();
            s.pop();
            inorder.push_back(curr->val);

            curr = curr->right;
        }

        return inorder;
    }

    bool inorderApproach(TreeNode* root){
        vector<int> inorder = getInorder(root);

        for(int i=0;i<inorder.size()-1;i++){
            if(inorder[i]>=inorder[i+1])
                return false;
        }

        return true;
    }
    bool isValidBST(TreeNode* root) {
        return inorderApproach(root);
    }
};