class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int first=0;
        int last=numbers.size()-1;
        vector<int>result;
        while(first<last){
            int sum=numbers[first]+numbers[last];
            if(sum == target){
                result.push_back(first+1);
                result.push_back(last+1);
                break;
            }
            if(sum<target)first++;
            else last--;
        }
        return result;
    }
};
