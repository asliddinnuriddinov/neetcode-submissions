class Solution {
    /**
     * @param {number[][]} matrix
     * @param {number} target
     * @return {boolean}
     */
    searchMatrix(matrix, target) {
        let sRow = 0
        let eRow = matrix.length-1
        let rowToCheck = null

        while( sRow <= eRow ){
            let mid = Math.floor( ( sRow + eRow ) / 2 )
            if( matrix[mid][0] <= target && matrix[mid][matrix[mid].length-1] >= target ){
                rowToCheck = mid
                break
            }
            else if( matrix[mid][0] < target ){
                sRow = mid + 1
            }else{
                eRow = mid - 1
            }
        }

        if( rowToCheck == null ){
            return false
        }

        let start = 0
        let end = matrix[rowToCheck].length-1

        while( start <= end ){
            let mid = Math.floor( ( start + end ) / 2 )
            if( matrix[rowToCheck][mid] === target ){
                return true
            }
            if( matrix[rowToCheck][mid] < target ){
                start = mid + 1
            }else{
                end = mid - 1
            }
        }
        return false
    }
}
