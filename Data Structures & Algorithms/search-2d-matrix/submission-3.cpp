class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int up = 0;
        int down = matrix.size() - 1;
        while(up <= down){
            int mid = up + (down - up)/2;
            if(matrix[mid][0] == target)return true;
            if(matrix[mid][0] < target )up = mid + 1;
            else if (matrix[mid][0] > target)down = mid - 1;
        }
        int row = max(0,up - 1);//found the row index
        cout << row << endl;
        int left = 0;
        int right = matrix[row].size() - 1;
        while(left <= right){
            int mid = left + (right - left)/2;
            int value = matrix[row][mid];
            if(value == target)return true;
            if(value < target)left = mid + 1;
            else if (value > target)right = mid - 1;
        }
        return false;
    }
};
