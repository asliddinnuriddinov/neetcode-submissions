class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, innerIdx;
        while(l <= r){
            int mid = (l + r) / 2;
            vector<int> &inner = matrix[mid];
            if(inner[0] <= target && inner[inner.size() - 1] >= target){
                innerIdx = mid;
                break;
            }
            else if(inner[0] > target) r = mid - 1;
            else l = mid + 1;
        }
        l = 0, r = matrix[innerIdx].size() - 1;

        while(l <= r){
            int mid = (l + r) / 2;
            if(matrix[innerIdx][mid] == target) return true;
            else if(matrix[innerIdx][mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
