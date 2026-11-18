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
private:
    void dfs(int cur , vector<vector<int>>& adj, vector<int>& visited){
        visited[cur] = 1;
        for(int neighbor : adj[cur]){
            if(!visited[neighbor]){
                dfs(neighbor, adj, visited);
            }
        }
    }
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        build(adj, edges);

        vector<int>visited(n);
        int count = 0;
        for(int i = 0; i < n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};
