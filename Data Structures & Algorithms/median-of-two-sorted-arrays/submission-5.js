class Solution {
    /**
     * @param {number[]} nums1
     * @param {number[]} nums2
     * @return {number}
     */
    findMedianSortedArrays(nums1, nums2) {
        let n = nums1.length + nums2.length
        let f = 0
        let s = 0
        let ind1 = Math.floor( n / 2 )
        let ind2 = Math.floor( n / 2 ) - 1
        let el1 = null
        let el2 = null
        let count = 0
         
        while( f < nums1.length || s < nums2.length ){
            let val
            if( f >= nums1.length ){
                val = nums2[s]
                s++
            }else if( s >= nums2.length ){
                val = nums1[f]
                f++
            }
            else if( nums1[f] < nums2[s] ){
                val = nums1[f]
                f++
            }else{
                val = nums2[s]
                s++
            }
            
            if( count == ind1 ){
                el1 = val
            }else if( count == ind2 ){
                el2 = val
            }
            count++
        }

        if( n % 2 == 0 ){
            return ( el1 + el2 ) / 2
        }else{
            return el1
        }
    }
}
