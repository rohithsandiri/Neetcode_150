class Solution {
private:
    int drow[4] = {-1,0,+1,0};
    int dcol[4] = {0,-1,0,+1};
    void dfs(int i , int j, int m , int n, vector<vector<char>>& board, char ch){
        board[i][j] = ch;
        for(int a = 0; a < 4; a++){
            int nrow = drow[a] + i;
            int ncol = dcol[a] + j;
            if(nrow >= 0 && ncol >= 0 && nrow < m && ncol < n && board[nrow][ncol] == 'O'){
                dfs(nrow,ncol, m,n,board,ch);
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        for(int i = 0; i < m; i++){
            if(board[i][0] == 'O'){
                dfs(i,0,m,n,board,'Y');
            }
            if(board[i][n-1] == 'O'){
                dfs(i,n-1,m,n,board,'Y');
            }
        }
        for(int j = 0; j < n; j++){
            if(board[0][j] == 'O'){
                dfs(0,j,m,n,board,'Y');
            }
            if(board[m-1][j] == 'O'){
                dfs(m-1,j,m,n,board,'Y');
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'O'){
                    dfs(i,j,m,n,board,'X');
                }
            }
        }
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(board[i][j] == 'Y'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
