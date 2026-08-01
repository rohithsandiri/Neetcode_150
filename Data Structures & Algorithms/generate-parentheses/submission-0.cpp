class Solution {
public:
    vector<string> result;

    void solve(int open , int close, int n , string& cur){
        if(cur.size() == 2*n){
            result.push_back(cur); 
        }

        if(open < n){
            cur.push_back('(');
            solve(open + 1, close, n , cur);
            cur.pop_back();
        }

        if(close < open){
            cur.push_back(')');
            solve(open, close + 1, n, cur);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string cur = "";
        solve(0, 0, n, cur);
        return result;
    }
};
