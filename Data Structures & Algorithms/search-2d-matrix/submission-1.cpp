class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        int up=0;
        int down=rows-1;
        int midr;
        int left=0;
        int right = cols-1;
        int midc;
        bool check = false;
        while(up<=down){
            midr=up+(down-up)/2;
            if(matrix[midr][left] <= target && target <= matrix[midr][right]){
                check=true;
                break;
            }
            else if(matrix[midr][left]> target){
                down=midr-1;
            }
            else if(matrix[midr][right] < target){
                up=midr+1;
            }
        }
        
        if(check){
            while(left<=right){
                midc=left + (right-left)/2;
                if(matrix[midr][midc] < target){
                    left=midc+1;
                }
                else if(matrix[midr][midc] > target){
                    right = midc-1;
                }
                else return true;
            }
        }
        std:: cout<< matrix[midr][midc]<<endl;
        return false;
        
    }
};
