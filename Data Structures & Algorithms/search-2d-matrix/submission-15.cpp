class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, inner = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            vector<int> &sub = matrix[mid];
            if(sub[0] <= target && sub[sub.size() - 1] >= target){
                inner = mid;
                break;
            }
            else if(sub[0] > target) r = mid - 1;
            else l = mid + 1;
        }
        if(inner == -1) return false;
        l = 0, r = matrix[inner].size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(matrix[inner][mid] == target) return true;
            else if(matrix[inner][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
