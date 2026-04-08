class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        //check if the rows are valid
        unordered_set<char>st;
        int i=0;int j=0;
        while(i<9){
            j=0;
            while(j<9){
                if(board[i][j]!='.' && st.count(board[i][j]))return false;
                else if(board[i][j]!='.' && !st.count(board[i][j]))st.insert(board[i][j]);
                j++;
            }
            i++;
            st.clear();
        }
        j=0;
        while(j<9){
            i=0;
            while(i<9){
                if(board[i][j]!='.' && st.count(board[i][j]))return false;
                else if(board[i][j]!='.' && !st.count(board[i][j]))st.insert(board[i][j]);
                i++;
            }
            j++;
            st.clear();
        }
        st.clear();
        for(int boxrow=0;boxrow<9;boxrow+=3){
            for(int boxcol=0;boxcol<9;boxcol+=3){
                unordered_set<char>st;
                for(int a=boxrow;a<boxrow+3;a++){
                    for(int b=boxcol;b<boxcol+3;b++){
                        if(board[a][b]=='.')continue;
                        else if(st.count(board[a][b])!=0)return false;
                        st.insert(board[a][b]);
                    }
                }
            }
        }
        return true;
        //check if the cols are valid
        //check if the 3*3 sub-boxes are valid

    }
};
