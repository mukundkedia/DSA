//https://leetcode.com/problems/serialize-and-deserialize-binary-tree/
//PC
//TBW


class Codec {
public:
    void preorder(TreeNode* root,string &ans){
        if(!root){
            ans+='#';
            ans+= ' ';
            return;
        }
        ans+=to_string(root->val);
        ans+=' ';
        preorder(root->left,ans);
        preorder(root->right,ans);
    }
    
    TreeNode* ds(stringstream& ss){
        string s;
        if(!(ss>>s)){
            return NULL;
        }
        if(s=="#"){
            return NULL;
        }
        TreeNode* newNode = new TreeNode(stoi(s));
        newNode->left = ds(ss);
        newNode->right = ds(ss);
        return newNode;
        
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string ans="";
        preorder(root,ans);
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return ds(ss);
    }
};