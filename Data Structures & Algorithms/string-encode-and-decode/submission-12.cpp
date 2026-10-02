class Solution {
    const string del = "&%#";
public:

    string encode(vector<string>& strs) {
        string result = "";
        int n = strs.size();
        for(int i = 0; i < n; i++){
            result += (strs[i]);
            result += (del);
        }
        return result;
    }

    vector<string> decode(string s) {
        vector<string>result;
        int start = 0;
        for(int i = 0; i < s.size(); i++){
            if(s[i] == del[0]){
                bool check = true;
                for(int k = i ; k <= i+del.size()-1; k++){
                    if(s[k] != del[k - i]){
                        check = false;
                        break;
                    }
                }
                if(check){
                    result.push_back(s.substr(start, i - start));
                    start = i +  del.size();
                }
            }
        }
        return result;
    }
};
