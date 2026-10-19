class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        int i = 0;
        string result = "";
        while(i < m && i < n){
            result.push_back(word1[i]);
            result.push_back(word2[i]);
            i++;
        }
        if(i < m){
            result.append(word1.substr(i));
        }
        else if(i < n){
            result.append(word2.substr(i));
        }
        return result;
    }
};