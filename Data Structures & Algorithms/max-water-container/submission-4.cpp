class Solution {
public:
    int maxArea(vector<int>& heights) {
        int left = 0;
        int n = heights.size();
        int right = n - 1;
        int max_area = 0;
        while(left < right){
            int area = (right - left) * min(heights[right],heights[left]);
            max_area = max(area, max_area);
            if(heights[left] < heights[right])left++;
            else right--;
        }
        return max_area;
    }
};
