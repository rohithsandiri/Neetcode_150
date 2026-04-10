class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int>mp;//character,last occured index;
        int n=s.size();
        for(int i=0;i<n;i++)mp[s[i]] = i;

        int start = 0;
        int end = start;

        vector<int>result;
        int i =0;
        while(i < n){
            end = max(end , mp[s[i]]);
            if( i == end){
                result.push_back(end - start + 1);
                start = i + 1;
                end = i + 1;
            }
            i++;
        }
        return result;
    }
};
