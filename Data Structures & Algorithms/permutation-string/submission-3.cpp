class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int l = 0;
        int r = s1.length() - 1;
        int count1[26] = {};
        for(char ch : s1){
            count1[ch - 'a']+=1;
        }
        int currCount = 0;
        while(r < s2.length()){
            int count2[26] = {};
            for(int i = l; i <= r; i++){
                count2[s2[i] - 'a']+=1;
            }
            for(char &ch : s1){
                if(count1[ch - 'a'] != count2[ch - 'a']){
                    l++;
                    r++;
                    currCount = 0;
                    break;
                }
                currCount++;
            }
            if(currCount == s1.length()) return true;
        }
        return false;
    }
};
