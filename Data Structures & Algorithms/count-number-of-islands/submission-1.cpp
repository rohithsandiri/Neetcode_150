class Solution {
    vector<int>drow = {-1,0,+1,0};
    vector<int>dcol = {0,-1,0,+1};
private:
    void dfs(int i , int j , int m , int n, vector<vector<char>>& grid){
        grid[i][j] = '0';
        for(int a = 0; a < 4; a++){
            int nrow = drow[a] + i;
            int ncol = dcol[a] + j;
            if(nrow < m && nrow >= 0 && ncol < n && ncol >= 0 && grid[nrow][ncol] == '1'){
                dfs(nrow,ncol, m, n, grid);
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        // for(int i = 0;i < m ; i++){
        //     if(grid[i][0] == '1'){
        //         dfs(i,0,m,n,grid);
        //     }
        //     if(grid[i][n-1] == '1'){
        //         dfs(i,n-1,m,n,grid);
        //     }
        // }
        // for(int j = 0;j < n ; j++){
        //     if(grid[0][j] == '1'){
        //         dfs(0,j,m,n,grid);
        //     }
        //     if(grid[m-1][j] == '1'){
        //         dfs(m-1,j,m,n,grid);
        //     }
        // }
        int count = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == '1'){
                    dfs(i,j,m,n,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
