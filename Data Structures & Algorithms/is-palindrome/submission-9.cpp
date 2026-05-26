class Solution {
public:
    bool isPalindrome(string s) {
        int l = 0, r = s.length() - 1;
        while(l < r){
            while(not isalnum(s[l])){
                l++;
            }
            while(not isalnum(s[r])){
                r--;
            }

            if(l < r and tolower(s[l]) != tolower(s[r])){
                return false;
            }
            r--;
            l++;
        }
        return true;
    }
};
