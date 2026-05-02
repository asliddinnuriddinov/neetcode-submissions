class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    isValidSudoku(arr) {
        let col={}
        let row={}
        let grids={}
        for(let i=0; i<arr.length; i++){
            for(let j=0; j<arr[i].length; j++){
                let subarr=arr[i]
                if(subarr[j]=='.') continue
                if(i+1 in row){
                    if(row[i+1].includes(subarr[j])){
                        return false
                    }
                    row[i+1]=[...row[i+1],subarr[j]]
                }else{
                    row[i+1]=[subarr[j]]
                }
                
                if(j+1 in col){
                    if(col[j+1].includes(subarr[j])){
                        return false
                    }
                    col[j+1]=[...col[j+1],subarr[j]]
                }else{
                    col[j+1]=[subarr[j]]
                }
            }
        }

        for(let i=0; i<arr.length; i++){
            let gridCol=parseInt(i/3)
            for(let j=0; j<arr[i].length; j++){
                let subarr=arr[i]
                let gridRow=parseInt(j/3)
                if(subarr[j]=='.') continue
                if(`${gridCol} ${gridRow}` in grids){
                    if(grids[`${gridCol} ${gridRow}`].includes(subarr[j])){
                        return false
                    }
                    grids[`${gridCol} ${gridRow}`]=[...grids[`${gridCol} ${gridRow}`],subarr[j]]
                }else{
                    grids[`${gridCol} ${gridRow}`]=[subarr[j]]
                }
            }
        }

        return true
    }
}
