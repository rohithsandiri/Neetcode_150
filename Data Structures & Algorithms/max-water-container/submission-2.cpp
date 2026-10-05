class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        int left = 0;
        int right = heights.size()-1;
        int max_area = 0;
        while(left < right){
            int h = min(heights[left] , heights[right]);
            int area = h*(right-left);
            max_area = max(area,max_area);
            if(heights[left] < heights[right])left++;
            else right--;
        }
        return max_area;
    }
};
