class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            int innerL = 0, innerR = matrix[mid].size() - 1;
            while(innerL <= innerR){
                int innerMid = innerL + (innerR - innerL) / 2;
                int num = matrix[mid][innerMid];
                if(num == target) return true;
                else if(num < target) innerL = innerMid + 1;
                else if(num > target) innerR = innerMid - 1;
            }
            if(matrix[mid][0] > target) r = mid - 1;
            else if(matrix[mid][0] < target) l = mid + 1;
        }
        return false;
    }
};
