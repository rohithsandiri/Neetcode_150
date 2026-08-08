class Solution {
public:
    string pattern = "##0##0?";

    string encode(vector<string>& strs) {
        string result = "";
        int n = strs.size();

        for(int i = 0; i < n; i++){
            result += strs[i];
            result += pattern;
        }
        
        return result;
    }

    vector<string> decode(string s) {
        int n = s.size();
        int i = 0; int start = 0; int j = 0;
        vector<string>result;

        while(j < n){
            if(s[j] == pattern[i]){
                i++;
            }

            if(i == 7){
                result.push_back(s.substr(start, j - 6 - start ));
                start = j + 1;
                i = 0;
            }
            
            j++;
        }

        return result;
    }
};
