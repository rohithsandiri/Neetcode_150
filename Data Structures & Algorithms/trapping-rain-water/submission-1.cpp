class Solution {
public:
    int trap(vector<int>& height) {
        int L=0;
        int R=height.size()-1;
        int maxL=height[L];
        int maxR=height[R];
        int TotalWater=0;
        while(L<R){
            if(maxL<maxR){
                L++;
                int water=maxL - height[L];
                if(water>0)TotalWater+=water;
                maxL=max(height[L],maxL);
            }
            else {
                R--;
                int water = maxR-height[R];
                if(water>0)TotalWater+=water;
                maxR=max(height[R],maxR);
            }
        }
        return TotalWater;
    }
};
