class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        //Boyer-Moore algorithm
        //floor(n/3) number of majority elements possible <= 2
        int n = nums.size();
        int count1 = 0; int count2 = 0;
        int candidate1 = 0;int candidate2 = 0;
        for(int x : nums){
            if(x == candidate1 && count1 > 0)count1++;
            else if (x == candidate2 && count2 > 0)count2++;
            else if(count1 == 0){
                candidate1 = x;
                count1++;
            }
            else if(count2 == 0){
                candidate2 = x;
                count2++;
            }
            else {
                count1--;
                count2--;
            }
        }
        vector<int>result;
        int c1 = 0;int c2 = 0;
        for(int x : nums){
            if(x == candidate1)c1++;
            else if(x == candidate2)c2++;
        }
        if(c1 > floor(n/3))result.push_back(candidate1);
        if(c2 > floor(n/3))result.push_back(candidate2);
        return result;
    }
};