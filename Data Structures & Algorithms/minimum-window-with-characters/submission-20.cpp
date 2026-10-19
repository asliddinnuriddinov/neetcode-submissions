class Solution {
public:
    string minWindow(string s, string t) {
        if(s.length() < t.length()) return "";
        int countS[128] = {}, countT[128] = {};
        int need = 0, have = 0;
        for(int i = 0; i < t.length(); i++){
            countT[t[i]]++;
            if(countT[t[i]] == 1) need++;
        }
        int l = 0, size = INT_MAX, resL = 0;
        for(int r = 0; r < s.length(); r++){
            countS[s[r]]++;
            if(countS[s[r]] == countT[s[r]]) have++;
            while(have == need){
                if(size > r - l + 1){
                    size = r - l + 1;
                    resL = l;
                }
                countS[s[l]]--;
                if(countS[s[l]] < countT[s[l]]) have--;
                l++;
            }
        }
        return size == INT_MAX ? "" : s.substr(resL, size);
    }
};
