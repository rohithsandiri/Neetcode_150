class Solution {
private:
    vector<int>drow = {-1, 0, +1, 0};
    vector<int>dcol = {0, -1, 0, +1};
    void dfs(int i , int j , int m , int n , vector<vector<int>>& grid, int& area){
        grid[i][j] = 0;
        area++;
        for(int a = 0; a < 4; a++){
            int nrow = drow[a] + i;
            int ncol = dcol[a] + j;
            if(nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1){
                dfs(nrow,ncol, m, n, grid, area);
            }
        }
    }
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int area = 0;
        int max_area = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m ; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1){
                    area = 0;
                    dfs(i,j,m,n,grid,area);
                    max_area = max(area,max_area);
                }
            }
        }
        return max_area;
    }
};
