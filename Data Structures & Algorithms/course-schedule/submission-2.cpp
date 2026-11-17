class Solution {
   private:
    void build(vector<vector<int>>& adj, vector<vector<int>>& p, int m) {
        for (int i = 0; i < m; i++) {
            int u = p[i][0];
            int v = p[i][1];
            adj[u].push_back(v);
        }
        return;
    }
    bool dfs(int i, vector<int>& visited, vector<int>& path, vector<vector<int>>& adj) {
        path[i] = 1;
        visited[i] = 1;
        for (int neighbor : adj[i]) {
            if(visited[neighbor] && path[neighbor])return true;
            if (!visited[neighbor] && dfs(neighbor, visited, path, adj)){
                return true;
            }
        }
        path[i] = 0;
        return false;
    }

   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int m = prerequisites.size();
        int n = prerequisites[0].size();
        vector<vector<int>> adj(numCourses);
        build(adj, prerequisites, m);

        vector<int> visited(numCourses);
        for (int i = 0; i < numCourses; i++) {
            if (!visited[i]) {
                vector<int> path(numCourses);
                if (dfs(i, visited, path, adj)) return false;
            }
        }
        return true;
    }
};
