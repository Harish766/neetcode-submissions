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
    int count=1;
    void dfs(TreeNode *root,int maxm){
        if(root==NULL){
            return;
        }
        if(root->val>=maxm){
            count++;
        }
        maxm=max(maxm,root->val);
        dfs(root->left,maxm);
        dfs(root->right,maxm);
        
    }
    int goodNodes(TreeNode* root) {
        dfs(root,root->val);
        return count-1;
    }
};
