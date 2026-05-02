class Solution {
    /**
     * @param {number[]} numbers
     * @param {number} target
     * @return {number[]}
     */
    twoSum(numbers, target) {
        let s=0
        let e=numbers.length-1
        while(s<e){
            while(numbers[s]+numbers[e]>target){
                e--
            }
            while(numbers[s]+numbers[e]<target){
                s++
            }
            if(numbers[s]+numbers[e]==target){
                return [s+1,e+1]
            }
        }
        
    }
}
