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
    int ans = 0;
    pair<int,int> solve(TreeNode* root){
        if(!root)return {0,0};

        auto [leftVal , leftSize] = solve(root->left);
        auto [rightVal , rightSize] = solve(root->right);

        int totalNode = leftSize + rightSize + 1;
        int totalSum = root->val + leftVal + rightVal;

        int avg = totalSum / totalNode;
        if(avg == root->val)ans++;

        return {totalSum , totalNode};
    }
    int averageOfSubtree(TreeNode* root) {
        auto temp = solve(root);

        return ans;
    }
};