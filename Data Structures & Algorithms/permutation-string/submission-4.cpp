class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length() > s2.length()) return false;
        int count1[26] = {};
        int count2[26] = {};
        for(int i = 0; i < s1.length(); i++){
            count1[ s1[i] - 'a' ]+=1;
            count2[ s2[i] - 'a' ]+=1;
        }
        int matches = 0;
        for(int i = 0; i < size(count1); i++){
            if(count1[i] == count2[i]){
                matches+=1;
            }
        }

        int l = 0;
        int r = s1.length();
        while(r < s2.length()){
            if(matches == 26) return true;

            int indexR = s2[r] - 'a';
            count2[indexR]+=1;
            if( count1[indexR] == count2[indexR] ){
                matches+=1;
            }
            else if( count1[indexR] + 1 == count2[indexR] ){
                matches-=1;
            }

            int indexL = s2[l] - 'a';
            count2[indexL]-=1;
            if( count1[indexL] == count2[indexL] ){
                matches+=1;
            }
            else if( count1[indexL] - 1 == count2[indexL] ){
                matches-=1;
            }
            l++;
            r++;
        }
        return matches == 26;
    }
};
