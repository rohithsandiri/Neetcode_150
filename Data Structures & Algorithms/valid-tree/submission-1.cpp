class Solution {
    void build_adj(vector<vector<int>>& edges,vector<vector<int>>& adj){
        for(auto x:edges){
            int a=x[0];int b=x[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
    }
    bool dfs(vector<vector<int>>& adj, int i,vector<int>& visited,int parent){
        visited[i]=1;
        for(int x: adj[i]){
            if(!visited[x]){
                if(!dfs(adj,x,visited,i))return false;
            }
            else if(parent!=x)return false;
        }
        return true;
    }
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        build_adj(edges,adj);
        vector<int>visited(n,0);
        if(!dfs(adj,0,visited,-1))return false;
        for(int x:visited){
            if(!x)return false;
        }
        return true;
    }
};
