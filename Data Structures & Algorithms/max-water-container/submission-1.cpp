class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0;
        int j=n-1;
        int max_Area=INT_MIN;
        while(i<j){

            
            int cur_Area=min(heights[i],heights[j])*(j-i);
            max_Area=max(cur_Area,max_Area);
            if(heights[i]<heights[j])i++;
            else j--;
        }
        return max_Area;
    }
};
