class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int count1[26] = {};
        int count2[26] = {};

        for(int i = 0; i < s1.length(); i++){
            count1[s1[i] - 'a']+=1;
            count2[s2[i] - 'a']+=1;
        }

        int matches = 0;

        for(int i = 0; i < size(count1); i++){
            if(count1[i] == count2[i]) matches+=1;
        }

        int l = 0, r = s1.length();

        while(r < s2.length()){
            if(matches == 26) return true;

            int index = s2[r] - 'a';
            count2[index]+=1;
            if(count1[index] == count2[index]) matches+=1;
            else if(count1[index] == count2[index] - 1) matches-=1;

            index = s2[l] - 'a';
            count2[index]-=1;
            if(count1[index] == count2[index]) matches+=1;
            else if(count1[index] - 1 == count2[index]) matches-=1;

            r++;
            l++;
        }
        return matches == 26;
    }
};
