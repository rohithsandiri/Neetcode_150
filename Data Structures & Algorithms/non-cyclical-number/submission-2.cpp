class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(n){
            int x = n;
            int sum = 0;
            while(x){
                int digit = x % 10;
                sum += (digit * digit);
                x = x / 10;
            }
            if(sum == 1)return true;
            if(st.find(sum) != st.end()){
                break;
            }
            st.insert(sum);
            n = sum ;
        }
        return false;
    }
};
