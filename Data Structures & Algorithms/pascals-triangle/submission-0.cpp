class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>result;
        vector<int>prev(1, 1);
        result.push_back(prev);
        for(int i = 2; i <= numRows; i++){
            vector<int>cur(i, 0);
            for(int j = 0; j < i; j++){
                int x = (j - 1) >= 0 ? prev[j - 1] : 0;
                int y = (j < i - 1) ? prev[j] : 0;
                cur[j] = x + y;
            }
            prev = cur;
            result.push_back(cur);
        }
        return result;
    }
};