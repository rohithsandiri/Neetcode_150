class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char>st;//store the chars
        int start = 0; int end = 0;
        int max_seen = 0;
        int n = s.size();
        while( end < n){
            if(st.find(s[end]) == st.end()){
                st.insert(s[end]);
                end++;
            }
            else {
                while(start <= end && st.find(s[end]) != st.end()){
                    st.erase(s[start]);
                    start++;
                }
                //remove the elements until repeat element also removed;
                
            }
            max_seen = max(max_seen, end-start);
        }
        return max_seen;
    }
};
