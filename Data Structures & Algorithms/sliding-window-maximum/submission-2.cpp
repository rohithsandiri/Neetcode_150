class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;//number , index
        int start=0;
        vector<int>result;
        while(start<k){
            if(!dq.empty() && dq.back().first<=nums[start]){
                dq.push_back({nums[start],start});
            }
            else {
                while(!dq.empty() && dq.front().first <= nums[start])dq.pop_front();
                dq.push_front({nums[start],start});
            }
            start++;

        }
        result.push_back(dq.back().first);
        int n=nums.size();
        while(start<n){
            if(!dq.empty() && dq.back().first <= nums[start]){
                dq.push_back({nums[start],start});
            }
            else 
            {
                while(!dq.empty() && dq.front().first  <= nums[start])dq.pop_front();
                dq.push_front({nums[start],start});
            }
            while(!dq.empty() && dq.back().second <= start - k){
                dq.pop_back();
            }
            if(!dq.empty()){
                result.push_back(dq.back().first);
            }
            start++;
        }
        return result;
    }
};
