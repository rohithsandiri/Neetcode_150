class Solution {
    void dfs(int val, int k, int n, vector<int>& running, vector<vector<int>>& result){
        running.push_back(val);
        if (running.size() == k) {
            result.push_back(running);
            running.pop_back();
            return;
        }

        for (int i = val+1; i <= n; i++) {
            dfs(i, k, n, running, result);
        }
       
        running.pop_back();
        return;
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> running;

        for (int i = 1; i <= n - k + 1; i++)
        dfs(i, k, n, running, result);
        return result;
    }
};