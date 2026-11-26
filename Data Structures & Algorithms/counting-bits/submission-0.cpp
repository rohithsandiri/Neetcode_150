class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result;
        for(int i = 0; i <= n; i++){
            int x = i;
            int count = 0;
            while(x){
                x = x & (x - 1);
                count++;
            }
            result.push_back(count);
        }
        return result;
    }
};
