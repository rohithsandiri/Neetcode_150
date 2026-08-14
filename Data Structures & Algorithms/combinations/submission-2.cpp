class Solution {
    void dfs(int val, int k, int n, vector<int>& running, vector<vector<int>>& result){
        running.push_back(val);
        if (running.size() == k) {
            result.push_back(running);
            running.pop_back();
            return;
        }

        for (int i = val; i <= n; i++) {
            if (i+1 <= n)
            dfs(i+1, k, n, running, result);
        }
        //if (running.size() > 0)
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