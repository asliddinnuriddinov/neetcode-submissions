class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char, int> mpt {};
        for(char &ch : t){
            mpt[ch]+=1;
        }
        int needed = mpt.size();
        int have = 0;

        unordered_map<char, int> mps {};
        int l = 0, r = 0;
        int resL = 0, resS = INT_MAX;

        while(r < s.length()){
            mps[s[r]]+=1;
            if(mpt.contains(s[r]) && mps[s[r]] == mpt[s[r]]) have+=1;

            while(have == needed){
                if(r - l + 1 < resS){
                    resL = l;
                    resS = r - l + 1;
                }

                mps[s[l]]-=1;
                if(mpt.contains(s[l]) && mps[s[l]] < mpt[s[l]]) have-=1;
                l++;
            }
            r++;
        }
        return resS == INT_MAX ? "" : s.substr(resL, resS);
    }
};
