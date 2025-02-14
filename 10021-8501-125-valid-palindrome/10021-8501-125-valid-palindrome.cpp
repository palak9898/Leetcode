class Solution {
public:
    bool isPalindrome(string s) {
        string s1 = "";

        for(char ch: s){
            if(isalnum(ch)){
                s1+= tolower(ch);
            }
        }
        int i = 0, j=s1.length()-1;
        while(i<j){
            if(s1[i]!=s1[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
};