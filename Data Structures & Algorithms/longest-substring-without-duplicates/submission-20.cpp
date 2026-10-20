class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_len = 0;
        unordered_map<char, int>mp;//character, index
        while(right < n){
            while(left < right && mp[s[right]] != 0){
                mp[s[left]]--;
                left++;
            }
            mp[s[right]]++;
            max_len = max(right - left + 1, max_len);
            right++;
        }
        return max_len;
    }
};
