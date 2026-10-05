class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>pre_max(n,0);
        vector<int>suf_max(n,0);
        for(int i = 0; i < n;i++){
            if(i>0){
                pre_max[i] = max(height[i-1], pre_max[i-1]);
            }
        }
        for(int i = n-1; i >= 0;i--){
            if(i < n-1){
                suf_max[i] = max(height[i+1], suf_max[i+1]);
            }
        }
        int total_rain = 0;
        for(int i = 0; i < n; i++){
            int rain = min(pre_max[i],suf_max[i]) - height[i];
            if(rain < 0)rain = 0;
            total_rain += rain;
        }
        return total_rain;
    }
};
