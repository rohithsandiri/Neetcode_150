class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        int maxA = 0;
        int maxB = 0;
        int maxC = 0;

        for(auto x: triplets){
            if(x[0] <= target[0] && x[1] <= target[1] && x[2] <= target[2]){
                maxA = max(maxA , x[0]);
                maxB = max(maxB , x[1]);
                maxC = max(maxC , x[2]);
            }

        }
        cout<< maxA <<" " << maxB << " "<< maxC << endl;
        if(maxA == target[0] && maxB == target[1] && maxC == target[2])return true;
        return false;
    }
};
