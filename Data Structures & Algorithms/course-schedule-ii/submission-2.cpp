class Solution {
private:
    void build(int m , vector<vector<int>>& adj, vector<vector<int>>& p){
        for(int i = 0;i < m; i ++){
            int x = p[i][0];
            int y = p[i][1];
            adj[y].push_back(x);
        }
    }
    bool dfs(int i, vector<vector<int>>& adj, vector<int>& visited, vector<int>& path, int n, vector<int>& result){
        path[i] = 1;
        visited[i] = 1;

        for(int neighbor : adj[i]){
            if(visited[neighbor] && path[neighbor])return true;
            if(!visited[neighbor]){
                if(dfs(neighbor, adj, visited, path, n,result))return true;
            }
        }

        path[i] = 0;
        result.push_back(i);
        return false;
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>result;
        int m = prerequisites.size();
        int n = prerequisites[0].size();
        vector<vector<int>>adj(numCourses);
        build(m,adj,prerequisites);
        vector<int>visited(numCourses);
        for(int i = 0 ; i < numCourses; i++){
            if(!visited[i]){
                vector<int>path(numCourses);
                if(dfs(i, adj, visited, path, numCourses,result))return {};

            }
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
