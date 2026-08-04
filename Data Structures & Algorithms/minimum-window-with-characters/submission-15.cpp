class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        int countT[128] {};
        int needed = 0, have = 0;
        for(char &ch : t){
            if(countT[ch] == 0) needed++;
            countT[ch]++;
        }
        int l = 0, resL = 0, resS = INT_MAX;
        int countS[128] {};
        for(int r = 0; r < s.length(); r++){
            char &ch = s[r];
            countS[ch]++;
            if(countS[ch] == countT[ch] && countT[ch] > 0) have++;

            while(have == needed){
                if(r - l + 1 < resS){
                    resL = l;
                    resS = r - l + 1;
                }
                countS[s[l]]--;
                if(countS[s[l]] < countT[s[l]]) have--;
                l++;
            }
        }
        return resS == INT_MAX ? "" : s.substr(resL, resS);
    }
};
