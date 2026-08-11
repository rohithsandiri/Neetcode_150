class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string result = "";
        int m = word1.size();
        int n = word2.size();
        int i = 0;
        int j = 0;

        while(i < m && j < n){
            result += word1[i];
            i++;

            result += word2[j];
            j++;
        }

        while(i < m){
            result += word1[i];
            i++;
        }

        while(j < n){
            result += word2[j];
            j++;
        }

        return result;
    }
};