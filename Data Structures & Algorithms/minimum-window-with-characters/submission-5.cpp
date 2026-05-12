class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpT {};
        for(char &ch : t){
            mpT[ch]+=1;
        }
        int needed = mpT.size();
        int have = 0;

        int resL = 0;
        int resS = INT_MAX;
        unordered_map<char, int> mpS {};
        int l = 0;
        for(int r = 0; r < s.length(); r++){
            mpS[s[r]]+=1;

            if(mpT.contains(s[r]) && mpT[s[r]] == mpS[s[r]]) have+=1;

            while(have == needed){
                if(r - l + 1 < resS){
                    resL = l;
                    resS = r - l + 1;
                }
                mpS[s[l]]-=1;
                if(mpT.contains(s[l]) && mpT[s[l]] > mpS[s[l]]) have-=1;
                l++;
            }
        }
        return resS == INT_MAX ? "" : s.substr(resL, resS);
    }
};
