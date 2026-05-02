class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mT = {};

        for(char &ch : t){
            mT[ch]+=1;
        }
        unordered_map<char, int> mS = {};
        int needed = mT.size();
        int have = 0;

        int l = 0, r = 0;

        int resL = 0;
        int resS = INT_MAX;

        while(r < s.length()){
            mS[s[r]]+=1;
            if(mT.contains(s[r]) && mT[s[r]] == mS[s[r]]){
                have+=1;
            }
            while(have == needed){
                mS[s[l]]-=1;
                if(mT.contains(s[l]) && mT[s[l]] - 1 == mS[s[l]]){
                    have-=1;
                }

                if(r - l + 1 < resS){
                    resL = l;
                    resS = r - l + 1;
                }
                l++;
            }
            r++;
        }
        if(resS == INT_MAX) return "";
        return s.substr(resL, resS);
    }
};
