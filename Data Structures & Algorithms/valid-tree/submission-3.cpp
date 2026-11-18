class Solution {
private:
    void build(vector<vector<int>>& adj, vector<vector<int>>& edges){
        for(int i = 0; i < edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    bool dfs(int i , int parent, vector<vector<int>>& adj, vector<int>& visited){
        visited[i] = 1;
        for(int neighbor : adj[i]){
            if(visited[neighbor]){
                if(parent == neighbor)continue;
                if(parent != neighbor)return true;
            }
            if(!visited[neighbor]){
                if(dfs(neighbor, i, adj, visited))return true;
            }
            
        }
        return false;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        build(adj, edges);
        
        int count = 0;
        vector<int>visited(n);

        for(int i = 0; i < n; i++){
            if(!visited[i]){
                if(dfs(i, -1, adj, visited))return false;
                count++;
            }
        }
        cout << count << endl;
        if(count > 1)return false;
        return true;
    }
};
