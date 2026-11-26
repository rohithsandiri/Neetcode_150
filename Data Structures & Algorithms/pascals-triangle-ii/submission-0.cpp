class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int>prev(1,1);
        for(int i = 2 ; i <= rowIndex + 1;i++){
            vector<int>cur(i,0);
            for(int j = 0; j < i; j++){
                int x = (j - 1) < 0 ? 0 : prev[j - 1];
                int y = (j < i - 1) ? prev[j] : 0;
                cur[j] = x + y;
            }
            prev = cur;
        }
        return prev;
    }
};