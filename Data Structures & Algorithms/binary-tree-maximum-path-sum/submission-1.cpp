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
    int maxm=INT_MIN;
    int ans(TreeNode *root){
        if(root==NULL){
            return 0;
        }
        int left = max(0,ans(root->left));
        int right= max(0,ans(root->right));
        int curr=root->val + left+right;
        maxm=max(maxm,curr);
        maxm=max(maxm,root->val);
        return root->val + max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int r=ans(root);
        return maxm;
    }
};
