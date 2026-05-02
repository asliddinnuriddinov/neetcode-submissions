class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length() > s.length()) return "";
        unordered_map<char, int> hash = {};
        unordered_map<char, int> window = {};

        for(char &ch : t){
            hash[ch]+=1;
        }

        int l = 0;
        int r = 0;

        int needed = hash.size();
        int have = 0;

        int res = 0;
        int resLen = INT_MAX;

        while(r < s.length()){
            window[s[r]]+=1;

            if( hash.contains(s[r]) && hash[s[r]] == window[s[r]] ){
                have+=1;
            }

            while(have == needed){
                if(r - l + 1 < resLen){
                    res = l;
                    resLen = r - l + 1;
                }

                window[s[l]]--;
                if( hash.contains(s[l]) && window[s[l]] < hash[s[l]] ){
                    have--;
                }
                l++;
            }
            r++;
        }
        if(resLen == INT_MAX) return "";
        return s.substr(res, resLen);
    }
};
