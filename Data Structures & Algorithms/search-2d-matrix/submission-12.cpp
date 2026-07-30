class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1;
        int innerInd = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            vector<int> &inner = matrix[mid];
            if(inner[0] <= target && inner[inner.size() - 1] >= target){
                innerInd = mid;
                break;
            }
            else if(inner[0] > target) r = mid - 1;
            else l = mid + 1;
        }
        if(innerInd == -1) return false;

        vector<int> &inner = matrix[innerInd];
        l = 0, r = inner.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(inner[mid] == target) return true;
            else if(target > inner[mid]) l = mid + 1;
            else r = mid - 1;
        }
        return false;
    }
};
