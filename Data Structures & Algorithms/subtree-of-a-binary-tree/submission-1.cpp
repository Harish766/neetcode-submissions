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
    bool check(TreeNode*p , TreeNode*q){
        if(p==NULL && q==NULL){
            return true;
        }
        if(p==NULL || q==NULL){
        return false;
        }
        if(p->val != q->val ){
        return false;
        }
        return check(p->left,q->left) && check(p->right,q->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root==NULL){
            return false;
        }
        if(subRoot->val==root->val && check(root,subRoot)){
            return true;
        }
        bool left=isSubtree(root->left,subRoot);
        bool right=isSubtree(root->right,subRoot);
        return left || right;
    }
};
