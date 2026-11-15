class Solution {
    int drow[4] = {-1,0,+1,0};
    int dcol[4] = {0,-1,0,+1};
private:
    void dfs(int i, int j, int m , int n ,vector<vector<int>>& heights,vector<vector<int>>& visited){
        visited[i][j] = -1;
        for(int a = 0; a < 4 ; a++){
            int nrow = i + drow[a];
            int ncol = j + dcol[a];
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && heights[i][j]<= heights[nrow][ncol] && visited[nrow][ncol] != -1){
                dfs(nrow,ncol,m,n,heights,visited);
            }
        }
    }
    // void atlantic(int i, int j, int m , int n ,vector<vector<int>>& heights,vector<vector<int>>& visited){
    //     visited[i][j] = 1;
    //     for(int a = 0; a < 4 ; a++){
    //         int nrow = i + drow[a];
    //         int ncol = j + dcol[a];
    //         if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && heights[i][j]<= heights[nrow][ncol]){
    //             atlantic(nrow,ncol,m,n,heights,visited);
    //         }
    //     }
    // }
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<int>>result;
        vector<vector<int>>visited_pacific(m,vector<int>(n,0));
        vector<vector<int>>visited_atlantic(m,vector<int>(n,0));
        for(int j = 0; j < n; j++){
            dfs(0,j,m,n,heights,visited_pacific);
        }
        for(int i = 0; i < m; i++){
            dfs(i,0,m,n,heights,visited_pacific);
        }
        for(int j = 0; j < n; j++){
            dfs(m-1,j,m,n,heights,visited_atlantic);
        }
        for(int i = 0; i < m; i++){
            dfs(i,n-1,m,n,heights,visited_atlantic);
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(visited_pacific[i][j] == -1 && visited_atlantic[i][j] == -1){
                    result.push_back({i,j});
                }
            }
        }
        return result;
    }
};
