class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, r = matrix.size() - 1, innerMid = -1;
        while(l <= r){
            int mid = (l + r) / 2;
            vector<int> &inner = matrix[mid];
            if(inner[0] <= target && target <= inner[inner.size() - 1]){
                innerMid = mid;
                break;
            }
            else if(inner[0] > target) r = mid - 1;
            else l = mid + 1;
        }
        if(innerMid == -1) return false;
        vector<int> &inner = matrix[innerMid];
        l = 0, r = inner.size() - 1;
        while(l <= r){
            int mid = (l + r) / 2;
            if(inner[mid] == target) return true;
            else if(inner[mid] > target) r = mid - 1;
            else l = mid + 1;
        }
        return false;
    }
};
