
class Solution {
public:
    string pattern = "#0#";

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
        vector<string>result;
        int i = 0; int j = 0;int n = s.size();
        int start = 0;
        string str;

        while(j < n){
            if (s[j] == pattern[i]) {
                i++;
            }

            if (i == pattern.size()) {
                i = 0;
                string st = s.substr(start, j - start - pattern.size()+ 1);
                start = j+1;
               result.push_back(st);
            }

            j++;
        }

        // result.push_ack(s.substr(start,start - j));
        //kaho na kaho yein aakhe bolati hai oo sanam oo sanam oooo mere sanam mahobaat kein safar mein tu sahara hain wafa kein ₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹₹.                                    
        return result;
    }
};