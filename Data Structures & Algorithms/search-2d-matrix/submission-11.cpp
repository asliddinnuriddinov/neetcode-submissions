class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int subMid;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int n = matrix[mid].size();
            if(matrix[mid][0] <= target && matrix[mid][n - 1] >= target){
                subMid = mid;
                break;
            }
            else if(target > matrix[mid][n - 1]) l = mid + 1;
            else r = mid - 1;
        }
        l = 0, r = matrix[subMid].size() - 1;

        while(l <= r){
            int mid = l + (r - l) / 2;
            if(matrix[subMid][mid] == target) return true;
            else if(matrix[subMid][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
