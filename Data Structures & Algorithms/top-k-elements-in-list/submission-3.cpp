class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>temp;
        sort(nums.begin(),nums.end(),greater<>());
        temp.push_back({1,nums[0]});
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                temp.back().first++;
            }
            else{
                temp.push_back({1,nums[i]});
            }
        }
        sort(temp.begin(),temp.end(),greater<>());
        vector<int>result;
        for(int i=0;i<k;i++){
            result.push_back(temp[i].second);
        }
        return result;
    }
};
