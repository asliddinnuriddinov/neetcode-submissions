class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int count1[26], count2[26];
        for(int i = 0; i < s1.length(); i++){
            count1[s1[i] - 'a']+=1;
            count2[s2[i] - 'a']+=1;
        }
        int matches = 0;
        for(int i = 0; i < size(count1); i++){
            if(count1[i] == count2[i]) matches+=1;
        }

        int l = 0;
        for(int r = s1.length(); r < s2.length(); r++){
            if(matches == 26) return true;
            int ind = s2[r] - 'a';
            count2[ind]+=1;

            if(count1[ind] == count2[ind]) matches+=1;
            else if(count1[ind] == count2[ind] - 1) matches-=1;

            ind = s2[l] - 'a';
            count2[ind]-=1;
            if(count1[ind] == count2[ind]) matches+=1;
            else if(count1[ind] == count2[ind] + 1) matches-=1;
            l++;
        }
        return matches == 26;
    }
};
