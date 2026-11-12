/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node)return nullptr;
        queue<Node*>q;
        unordered_map<Node*, Node*>mp;//old, clone
        mp[node] = new Node(node->val);
        q.push(node);
        while(!q.empty()){
            int size = q.size();
            while(size--){
                Node* temp = q.front();
                q.pop();
                for(auto n : temp -> neighbors){
                    if(mp.find(n) == mp.end()){
                        mp[n] = new Node(n -> val);
                        q.push(n);
                    }
                    mp[temp]->neighbors.push_back(mp[n]);
                }
            }
        }
        return mp[node];
    }
};
