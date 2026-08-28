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
    void solve(TreeNode* root,string curr,vector<string>& ans){
        if(!root->left && !root->right){
            curr += to_string(root->val);
            ans.push_back(curr);
            return;
        }


        if(root->left) solve(root->left,curr + to_string(root->val) + "->",ans);
        if(root->right) solve(root->right,curr + to_string(root->val) + "->",ans);


    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        solve(root,"",ans);

        return ans;
    }
};