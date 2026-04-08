class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int>s;
        if(!nums.size())return 0;
        for(int x:nums){
            s.insert(x);
        }
        int count=0;
        int max_count=1;
        for(int x:nums){
            if(s.find(x-1)==s.end()){
                count=1;
                while(s.find(x+1)!=s.end()){
                    count++;
                    max_count=max(count,max_count);
                    x++;
                }
            }
        }
        return max_count;
    }
};
