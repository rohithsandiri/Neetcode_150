class Solution {
    vector<int>drow = {-1,0,+1,0};
    vector<int>dcol = {0,-1,0,+1};
    void bfs(int m , int n , queue<pair<int,int>>& q, vector<vector<int>>& grid){
        int level = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                for(int i = 0; i < 4; i++){
                    int nrow = x + drow[i];
                    int ncol = y + dcol[i];
                    if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && grid[nrow][ncol] == 2147483647){
                        grid[nrow][ncol] = level + 1;
                        q.push({nrow,ncol});
                    }
                }
            }
            level++;
        }
    }
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;//indices of treasures
        int m = grid.size();
        int n = grid[0].size();
        for(int i = 0;i < m; i ++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    q.push({i,j});
                }
            }
        }
        bfs(m,n,q,grid);
    }
};
