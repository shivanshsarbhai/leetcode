/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans = "";
        if(!root)
            return ",";

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* top = q.front();
            q.pop();

            if(!top){
                ans += "#,";
                continue;
            }
            ans+=to_string(top->val) + ",";
            q.push(top->left);
            q.push(top->right);
        }
        // cout<<"Serialized string is : "<<ans<<endl;
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data == ",")
            return NULL;
        
        stringstream ss(data);
        vector<string>nums;
        string s;
        while (getline(ss, s, ',')) {
            nums.push_back(s);
        }

        TreeNode* root = new TreeNode(stoi(nums[0]));
        int index = 1;  
        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            //left child of root    
            if(nums[index]!="#"){
                TreeNode* leftChild = new TreeNode(stoi(nums[index++]));
                curr->left = leftChild;
                q.push(leftChild);
            } else {
                curr->left = NULL;
                index++;
            }

            //left child of root    
            if(nums[index]!="#"){
                TreeNode* rightChild = new TreeNode(stoi(nums[index++]));
                curr->right = rightChild;
                q.push(rightChild);
            } else {
                curr->right = NULL;
                index++;
            }
        }

        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

/*
0 1 2 3 4 5 6
_
  - - 
      - - - - 

*/