class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        for(int i=0;i<n;i++){
            if(i>0 && nums[i]==nums[i-1])continue;
            int first=i+1;
            int last=n-1;
            while(first<last){
                vector<int>temp;
                int sum=nums[first]+nums[last];
                if(sum == -nums[i]){
                    if(first < last && nums[first]==nums[first+1])first++;
                    if(first < last && nums[last]==nums[last-1])last--;
                    temp.push_back(nums[i]);
                    temp.push_back(nums[first]);
                    temp.push_back(nums[last]);
                    result.push_back(temp);
                    first++;
                    last--;
                }
                else if(sum > -nums[i])last--;
                else if(sum < -nums[i])first++;
            }
        }
        for(int i=0;i<result.size();i++){
            
        }
        return result;
    }
};
