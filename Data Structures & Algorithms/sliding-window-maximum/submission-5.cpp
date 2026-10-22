class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<pair<int,int>>dq;//value, index
        vector<int>result;
        int n = nums.size();
        for(int i = 0; i < n; i ++){
            //pushing a new element
            //1.remove the smaller elements from the front
            while(!dq.empty() && nums[i] >= dq.front().first)dq.pop_front();
            //2.insert the new element now in the front
            dq.push_front({nums[i],i});

            //take the maximum value if i >= k
            if(i + 1 >= k){
                //pop all the elements from the back if they are out of window
                int valid = i - k;
                while(!dq.empty() && dq.back().second <= valid)dq.pop_back();
                if(!dq.empty()){
                    result.push_back(dq.back().first);
                }
            }
        }
        return result;
    }
};
