class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int l = 0;
        unordered_map<char, int> myMap;
        int maxFreq = 0;
        for(int r = 0; r < s.length(); r++){
            int winLength = r - l + 1;
            myMap[s[r]]+=1;  
            maxFreq = max(maxFreq, myMap[s[r]]);
            int diff = winLength - maxFreq;
            while(diff > k){
                myMap[s[l]]-=1; 
                l++;
                winLength = r - l + 1;
                diff = winLength - maxFreq;
            }
            if(winLength > maxLength) maxLength = winLength;
        }
        return maxLength;
    }
};
