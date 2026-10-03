class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max_seen = 0;
        int n = nums.size();
        unordered_set<int>st;//store the elements of the nums
        for(int x : nums){
            st.insert(x);
        }
        for(int i = 0; i < n; i++){
            int x = nums[i];
            int count = 1;
            if(st.find(x-1) == st.end()){
                while(st.find(x+1) != st.end()){
                    count++;
                    x++;
                }
            }
            max_seen = max(max_seen, count);
        }
        return max_seen;
    }
};
