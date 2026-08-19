class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int count1[128] = {}, count2[128] = {};

        for(int i = 0; i < s1.length(); i++){
            count1[s1[i]]++;
            count2[s2[i]]++;
        }
        int matches = 0;
        for(int i = 0; i < size(count1); i++){
            if(count1[i] == count2[i]) matches++;
        }
        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++){
            if(matches == 128) return true;
            count2[s2[r]]++;

            if(count1[s2[r]] == count2[s2[r]]) matches++;
            else if(count1[s2[r]] + 1 == count2[s2[r]]) matches--;

            count2[s2[l]]--;
            if(count1[s2[l]] == count2[s2[l]]) matches++;
            else if(count1[s2[l]] == count2[s2[l]] + 1) matches--;

            l++;
        }
        return matches == 128;
    }
};
