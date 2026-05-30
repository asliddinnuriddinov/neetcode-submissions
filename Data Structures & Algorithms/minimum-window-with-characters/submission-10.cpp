class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        int countT[128];
        int needed = 0, have = 0, l = 0;
        for(char &ch : t){
            if(countT[ch] == 0) needed+=1;
            countT[ch]+=1;
        }
        int resL = 0, resS = INT_MAX;
        int countS[128];
        for(int r = 0; r < s.length(); r++){
            countS[s[r]]+=1;
            if(countT[s[r]] > 0 && countT[s[r]] == countS[s[r]]) have+=1;

            while(have == needed){
                if(r - l + 1 < resS){
                    resL = l;
                    resS = r - l + 1;
                }
                countS[s[l]]-=1;
                if(countT[s[l]] > 0 && countT[s[l]] > countS[s[l]]) have-=1;
                l++;
            }
        }
        return resS == INT_MAX ? "" : s.substr(resL, resS);
    }
};
