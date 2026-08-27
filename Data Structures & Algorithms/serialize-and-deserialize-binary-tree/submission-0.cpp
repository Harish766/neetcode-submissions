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

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        queue<TreeNode*> q;
        if(root==NULL){
            return "";
        }
        q.push(root);
        string s="";
        s += to_string(root->val) + ",";
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode *fi;
                fi=q.front();
                q.pop();
                if(fi->left){
                    q.push(fi->left);
                    s+=to_string(fi->left->val) + ",";
                }else{
                    s+="null,";
                }
                if(fi->right){
                    q.push(fi->right);
                    s+=to_string(fi->right->val)+ ",";
                }else{
                    s+="null,";
                }
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){
            return NULL;
        }
        vector<string> nodes;
    int start = 0;
    
    for (int i = 0; i < data.size(); i++) {
        if (data[i] == ',') { 
            string curr = data.substr(start, i - start); 
            nodes.push_back(curr);
            start = i + 1; 
        }
    }
        TreeNode *root = new TreeNode(stoi(nodes[0]));
        queue<TreeNode*> q;
        q.push(root);
        int index=1;
        while(!q.empty()){

            TreeNode* parent = q.front();
            q.pop();
            if(index<nodes.size()){
            if(nodes[index]!="null"){
                parent->left = new TreeNode(stoi(nodes[index]));
                q.push(parent->left);
            }
            index++;
            }
            if(index<nodes.size()){
            if(nodes[index]!="null"){
                parent->right = new TreeNode(stoi(nodes[index]));
                q.push(parent->right);
            }
            index++;
            }
        }
        return root;
    }
    };
