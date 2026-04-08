class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int L=0;
        int R=n-1;
        int maxLeft=height[L];
        int maxRight=height[R];
        int TotalWater=0;
        while(L<R){
            if(maxLeft<maxRight){
                L++;
                int water=min(maxRight,maxLeft)-height[L];
                if(water>0){
                    TotalWater=water+TotalWater;
                }
                maxLeft=max(height[L],maxLeft);
            }
            else{
                R--;
                int water=min(maxRight,maxLeft)-height[R];
                if(water>0){
                    TotalWater=water+TotalWater;
                }
                maxRight=max(height[R],maxRight);
            }
        }
        return TotalWater;

    }
};
