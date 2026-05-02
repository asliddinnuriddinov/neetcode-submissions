class Solution {
    /**
     * @param {character[][]} board
     * @return {boolean}
     */
    isValidSudoku(board) {
        const row={}, column={}
        for(let i=0; i<board.length; i++){
            for(let j=0; j<board[i].length; j++){
                if( board[i][j] == "." ) continue
                if( i+1 in row ){
                    if( row[i+1].includes(board[i][j]) ) return false
                    row[i+1] = [...row[i+1], board[i][j] ]
                }else{
                    row[i+1] = [ board[i][j] ]
                }
                if( j+1 in column ){
                    if( column[j+1].includes(board[i][j]) ) return false
                    column[j+1] = [...column[j+1], board[i][j] ]
                }else{
                    column[j+1] = [ board[i][j] ]
                }
            }
        }
        const grid={}
        for(let i=0; i<board.length; i++){
            const rowInd= Math.floor(i/3)
            for(let j=0; j<board[i].length; j++){
                if( board[i][j] == "." ) continue
                const columnInd = Math.floor(j/3)
                const pos = `${rowInd} ${columnInd}`
                if( pos in grid ){
                    if( grid[pos].includes(board[i][j]) ){
                        console.log(board[i][j])
                        return false
                    }
                    grid[pos] = [ ...grid[pos], board[i][j] ]
                }else{
                    grid[pos] = [ board[i][j] ]
                }
            }
        }
        console.log(grid)
        return true
    }
}
