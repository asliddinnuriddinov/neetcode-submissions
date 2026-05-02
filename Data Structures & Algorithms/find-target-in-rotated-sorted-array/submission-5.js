class Solution {
    /**
     * @param {number[]} nums
     * @param {number} target
     * @return {number}
     */
    search(nums, target) {
        let L = 0
        let R = nums.length-1

        while( L <= R ){
            let mid = Math.floor( ( L + R ) / 2 )

            if( nums[mid] === target ) return mid

    if (nums[L] <= nums[mid]) {
        if (nums[L] <= target && target < nums[mid]) {
            R = mid - 1;  // Target in left half
        } else {
            L = mid + 1;  // Target in right half
        }
    }
    // Right half is sorted
    else {
        if (nums[mid] < target && target <= nums[R]) {
            L = mid + 1;  // Target in right half
        } else {
            R = mid - 1;  // Target in left half
        }
    }
        }

        return -1
    }
}
