class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>st;
        for(int i : nums){
            st.insert(i);
        }
        int max_seq = 0;
        for(int i = 0;i < nums.size();i++){
            if(st.find(nums[i]) != st.end() && st.find(nums[i] -1) == st.end()){
                int j = nums[i];
                int count = 1;
                while(st.find(++j) != st.end()){
                    count++;
                }
                max_seq = max(max_seq, count);
            }
        }
        return max_seq;
    }
};
