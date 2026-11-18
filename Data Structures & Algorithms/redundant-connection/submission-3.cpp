class Solution {
    bool dfs(int s, int d, vector<vector<int>>& adj, vector<int>& visited, int parent){
        visited[s] = 1;
        for(int neighbor : adj[s]){
            if((neighbor == d))return true;
            if(!visited[neighbor]){
                if(dfs(neighbor, d, adj, visited, neighbor))return true;
            }
        }
        return false;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int m = edges.size();
        int n = edges[0].size();
        int size = 0;
        for(auto x : edges){
            int u = x[0];
            int v = x[1];
            size = max(size, max(u,v));
        }
        vector<vector<int>>adj(size + 1);
        vector<int>result(2);
        vector<int>visited(size + 1);
        for(int i = 0; i < m; i ++){
            int src = edges[i][0];
            int dest = edges[i][1];
            if(!visited[src] || !visited[dest]){
                visited[src] = 1;
                visited[dest] = 1;
                adj[src].push_back(dest);
                adj[dest].push_back(src);
            }
            else{
                vector<int>v(size + 1);
                if(dfs(src,dest,adj,v, -1)){
                    result[0] = src;
                    result[1] = dest;
                    return result;
                }
                else {
                    adj[src].push_back(dest);
                    adj[dest].push_back(src);
                }
            }
        }
        return result;
    }
};
