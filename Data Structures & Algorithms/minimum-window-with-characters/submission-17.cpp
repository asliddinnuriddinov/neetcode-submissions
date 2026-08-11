class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        int countS[128] = {}, countT[128] = {};

        for(int i = 0; i < t.length(); i++){
            countT[t[i]]++;
        }

        int needed = 0, have = 0;
        for(int &ct : countT){
            if(ct > 0) needed++;
        }

        int l = 0, resM = INT_MAX, resL = 0;
        for(int r = 0; r < s.length(); r++){
            countS[s[r]]++;
            if(countS[s[r]] == countT[s[r]]) have++;

            while(have == needed){
                if(r - l + 1 < resM){
                    resL = l;
                    resM = r - l + 1;
                }
                countS[s[l]]--;
                if(countS[s[l]] < countT[s[l]]) have--;
                l++;
            }
        }
        return resM == INT_MAX ? "" : s.substr(resL, resM);
    }
};
