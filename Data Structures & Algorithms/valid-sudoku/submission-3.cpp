class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>st; //insert the seen elements of the board ;
        //explore all the rows
        int rows = board.size();
        int cols = board[0].size();
        for(int i = 0 ; i < rows; i++ ){
            for(int j = 0; j < cols; j++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end())return false;
                st.insert(board[i][j]);
            }
            st.clear();
        }
        //explore all the cols 
        st.clear();

        for(int j = 0; j < cols; j++){
            for (int i = 0; i < rows ; i ++){
                if(board[i][j] == '.') continue;
                if(st.find(board[i][j]) != st.end())return false;
                st.insert(board[i][j]);
            }
            st.clear();
        }
        st.clear();
        //explore all the smaller squares 3*3
        for(int row = 0 ; row < 9; row +=3){
            for(int col = 0 ; col < 9 ; col +=3){
                st.clear();
                for(int i = row ; i < row + 3; i++){
                    for(int j = col; j < col + 3; j++){
                        if(board[i][j] == '.') continue;
                        if(st.find(board[i][j]) != st.end())return false;
                        st.insert(board[i][j]);
                    }
                }
            }
        }
        return true;
    }
};
