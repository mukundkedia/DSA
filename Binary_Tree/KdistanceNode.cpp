// https://leetcode.com/problems/all-nodes-distance-k-in-binary-tree/
// PC
//TBW

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public: queue<TreeNode*> q;
        set<TreeNode*> set1;
    unordered_map<TreeNode*,TreeNode*> map1;
    
    void makeParent(TreeNode* root,TreeNode* parent){
        if(!root){
            return;
        }
        map1[root] = parent;
        makeParent(root->left,root);
        makeParent(root->right,root);
    
    }
    
    void nextLevel(){
        while(1){
            TreeNode* temp = q.front();
            q.pop();
            if(!temp){
                if(q.size()!=0){
                    q.push(NULL);
                   
                }
                return;
            }
            if(temp->left and set1.find(temp->left)==set1.end()){
                q.push(temp->left);
                set1.insert(temp->left);
            }
            if(temp->right and set1.find(temp->right)==set1.end()){
                q.push(temp->right);
                set1.insert(temp->right);
            }
            if(map1[temp] and set1.find(map1[temp])==set1.end()){
                q.push(map1[temp]);
                set1.insert(map1[temp]);
            }
        }
    }
    
    TreeNode* findNode(TreeNode* root,TreeNode* target){
        if(!root){
            return NULL;
        }
        if(root->val==target->val){
            return root;
        }
        TreeNode* l = findNode(root->left,target);
        if(l){
            return l;
        }
        TreeNode* r = findNode(root->right,target);
        if(r){
            return r;
        }
        return NULL;
    }
        
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        vector<int> ans;
        
        TreeNode* parent = NULL;
        if(!root){
            return ans;
        }
        makeParent(root,parent);
        TreeNode* start = findNode(root,target);
        if(!start){
            return ans;
        }
        int count=0;
       
        q.push(start);
        q.push(NULL);
        set1.insert(start);
        while(!q.empty()){
            if(count==K){
                while(!q.empty()){
                    TreeNode* temp = q.front();
                    q.pop();
                    if(temp){
                        ans.push_back(temp->val);
                    }
                }
                return ans;
            }
            count++;
            nextLevel();
        }
        return ans;
    }
};