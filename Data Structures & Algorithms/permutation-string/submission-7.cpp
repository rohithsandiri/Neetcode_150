class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int>arr1(26,0);
        vector<int>arr2(26,0);
        int m = s1.size();
        int n = s2.size();
        for(char c : s1){
            arr1[c - 'a']++;
        }
        int left = 0;
        int right = 0;
        int count = 0;
        for(int x : arr1){
            if(x == 0)count++;
        }
        while(right < n){
            //incoming
            arr2[s2[right] - 'a']++;
            int incoming = s2[right] - 'a';
            if(arr1[incoming] == arr2[incoming])count++;
            if(arr1[incoming] + 1 == arr2[incoming])count--;
            
            //outgoing
            if(right - left + 1 > m){
                int outgoing = s2[left] - 'a';
                arr2[outgoing]--;
                if(arr1[outgoing] == arr2[outgoing])count++;
                if(arr1[outgoing] == arr2[outgoing]+1)count--;
                left++;
            }
            if(count == 26 && right - left + 1  == m)return true;
            right++;
        }
        return false;
    }
};
