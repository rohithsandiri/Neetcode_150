class Solution {
private:
    void dfs(int i, int j, vector<vector<char>> &grid, vector<int>& drow, vector<int>& dcol, int m, int n){
        grid[i][j] = '0';

        for(int a = 0; a<4; a++ ){
            int nrow = i + drow[a];
            int ncol = j + dcol[a];

            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == '1'){
                dfs(nrow, ncol, grid, drow, dcol, m, n);
            }
        }

    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int>drow = {0, -1, 0, +1};
        vector<int>dcol = {-1, 0, +1, 0};

        int count = 0;
        for(int i = 0; i<m; i++){
            for(int j = 0; j< n; j++){
                if(grid[i][j] == '1'){
                    dfs(i , j, grid, drow, dcol, m, n);
                    count++;
                }
            }
        }
        return count;
    }
};
