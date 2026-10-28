class Solution {
private:
    void solve(vector<vector<int>>& matrix, int i, int j, int m, int n){
        for(int x=0; x< n;x++){
            if(matrix[i][x]== 0)continue;
            else matrix[i][x] = -1;
        }
        for(int x=0; x< m;x++){
            if(matrix[x][j] == 0)continue;
            else matrix[x][j] = -1;
        }
        return;
    }
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i = 0; i < rows;i ++){
            for(int j = 0; j < cols; j++){
                if(matrix[i][j] == 0){
                    solve(matrix,i,j,rows,cols);
                }
            }
        }
        for(int i = 0; i< rows;i++){
            for(int j = 0; j < cols;j++){
                if(matrix[i][j] == -1)matrix[i][j] = 0;
            }
        }
        return;
    }
};
