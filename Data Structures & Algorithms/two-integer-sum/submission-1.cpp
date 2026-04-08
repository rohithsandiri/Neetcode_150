class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>>list;
        for(int i=0;i<nums.size();i++){
            list.push_back({nums[i],i});
        }
        int i=0;
        int n=nums.size()-1;
        sort(list.begin(),list.end());
        vector<int>result;
        while (i<=n){
            int a=list[i].first;
            int b=list[n].first;
            if(a+b > target)n--;
            else if(a+b <target)i++;
            else if(a+b == target){
                result.push_back(list[i].second);
                result.push_back(list[n].second);
                break;
            }
        }
        sort(result.begin(),result.end());
        return result;
    }
};
