class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {};
        for(char &ch : s){
            count[ch - 'a'] += 1;
        }
        for(char &ch : t){
            count[ch - 'a'] -= 1;
        }
        for(int &c : count){
            if(c != 0) return false;
        }
        return true;
    }
};
