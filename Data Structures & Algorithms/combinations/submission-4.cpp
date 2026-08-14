class Solution {
    void dfs(int start, int k, int n, vector<int>& path, vector<vector<int>>& result) {
        if (path.size() == k) {
            result.push_back(path);
            return;
        }
        
        // Only loop up to n - (k - path.size()) + 1
        for (int i = start; i <= n - (k - (int)path.size()) + 1; i++) {
            path.push_back(i);
            dfs(i + 1, k, n, path, result);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(1, k, n, path, result);
        return result;
    }
};