class VectorHash {
public: 
    size_t operator()(const vector<int>& v)const{
        size_t hash = 0;

        for(int x : v){
            hash = hash * 37 + x;
        }
        return hash;
    }
};

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<vector<int>, vector<string>, VectorHash>mp;
        for(string s : strs){
            vector<int> freq(26,0);
            for(char c : s){
                freq[c - 'a']++;
            }

            mp[freq].push_back(s);
        }
        vector<vector<string>>result;
        for(auto x : mp){
            result.push_back(x.second);
        }
        return result;
    }
};
