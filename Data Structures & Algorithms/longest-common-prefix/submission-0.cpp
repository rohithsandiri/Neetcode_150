class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int index = 0;
        int n = strs.size();
        string result = "";
        while(1){
            char ch;
            int i = 0;
            if(index < strs[i].size())ch = strs[i][index];
            else return result;
            while(i<n){
                if(index < strs[i].size() && strs[i][index] == ch){
                    i++;
                    continue;
                }
                return result;
            }
            result.push_back(ch);
            index++;
        }
        return result;
    }
};