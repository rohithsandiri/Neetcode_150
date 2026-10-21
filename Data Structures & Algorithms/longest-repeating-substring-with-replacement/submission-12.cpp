class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<int,int>mp;//char, freq
        int n = s.size();
        int left = 0;
        int right = 0;
        int max_len = 0;
        int max_freq = 0;
        while(right < n){
            mp[s[right]]++;
            max_freq = max(max_freq, mp[s[right]]);
            if(right - left + 1 - max_freq > k){
                mp[s[left++]]--;
            }
            max_len = max(right - left + 1 , max_len);
            right++;
        }
        return max_len;
    }
};
