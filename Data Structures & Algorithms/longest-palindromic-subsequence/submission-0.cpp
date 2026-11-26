class Solution {
private:
    int LCS(string& a, string& b, int n ){
        vector<int>prev(n + 1, 0);
        for(int i = 1; i <= n; i++){
            vector<int>cur(n + 1);
            for(int j = 1; j <= n; j++){
                if(a[i-1] == b[j-1])cur[j] = 1 + prev[j-1];
                else{
                    cur[j] = max(prev[j], cur[j-1]);
                }
            }
            prev = cur;
        }
        return prev[n];
    }
public:
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        int n = s.size();
        return LCS(s,t,n);
    }
};