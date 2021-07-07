//https://leetcode.com/problems/clone-graph/

class Solution {
public:
    unordered_map<Node*,Node*> vis;
    
    Node* cloneGraph(Node* node) {
        if(!node){
            return NULL;
        }
        Node* copy = new Node(node->val,{});
        vis[node]=copy;
        queue<Node*> q;
        q.push(node);
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            for(Node* neighbor: curr->neighbors){
                if(vis.find(neighbor)==vis.end()){
                    vis[neighbor]=new Node(neighbor->val,{});
                    q.push(neighbor);
                }
                vis[curr]->neighbors.push_back(vis[neighbor]);
            }
            
        }
        return copy;
    }
};