class TimeMap {
    constructor() {
        this.keyStore = new Map();
    }

    /**
     * @param {string} key
     * @param {string} value
     * @param {number} timestamp
     * @return {void}
     */
    set(key, value, timestamp) {
        if (this.keyStore.has(key)) {
            this.keyStore.get(key).push([value, timestamp]);  // Append to existing array
        } else {
            this.keyStore.set(key, [[value, timestamp]]); // Initialize array if key does not exist
        }
    }

    /**
     * @param {string} key
     * @param {number} timestamp
     * @return {string}
     */
    get(key, timestamp) {
        if (!this.keyStore.has(key)) return ""
        let l = 0 
        let r = this.keyStore.get(key).length - 1
        const arr = this.keyStore.get(key)
        while( l <= r ){
            const mid  = Math.floor( ( l + r) / 2 )
            if( arr[mid][1] === timestamp ) return arr[mid][0]
            
            if( arr[mid][1] > timestamp ){
                r = mid - 1
            }else{
                l = mid + 1
            }
        }
        if( r > -1 ){
            return arr[r][0]
        }
        return ""
    }
}