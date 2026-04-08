/*class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if(nums.size()==0)return 0;
        sort(nums.begin(),nums.end());
        int count=0;
        int max_count=0;
        vector<int>input;
        input.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i-1]!=nums[i]){
                input.push_back(nums[i]);
            }
        }
        for(int i=1;i<input.size();i++){
            if(input[i]-input[i-1]==1){
                count++;
                max_count=max(count,max_count);
            }
            else count=0;
        }
        return max_count +1;
    }
};*/
class Solution{
public:
    int longestConsecutive(vector<int>& nums){
        unordered_set<int>st(nums.begin(),nums.end());
        int max_len=0;
        for(int num:st){
            if(!st.count(num-1)){
                int cur=num;
                int length=1;
                while(st.count(cur+1)){
                    cur++;
                    length++;
                }
                max_len=max(length,max_len);
            }
        }
        return max_len;
    }
};
