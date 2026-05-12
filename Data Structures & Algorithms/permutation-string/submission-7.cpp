class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {};
        int count2[26] = {};
        for(int i = 0; i < s1.length(); i++){
            count1[s1[i] - 'a']++;
            count2[s2[i] - 'a']++;
        }
        int matches = 0;
        for(int i = 0; i < size(count1); i++){
            if(count1[i] == count2[i]) matches++;
        }

        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++){
            if(matches == 26) return true;
            int idx = s2[r] - 'a';
            count2[idx]+=1;

            if(count1[idx] == count2[idx]) matches++;
            else if(count1[idx] + 1 == count2[idx]) matches--;

            idx = s2[l] - 'a';
            count2[idx]-=1;

            if(count1[idx] == count2[idx]) matches++;
            else if(count1[idx] - 1 == count2[idx]) matches--;
            l++;
        }
        return matches == 26;
    }
};
