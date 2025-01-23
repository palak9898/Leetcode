class Solution {
public:
    bool isPalindrome(int x) {
        string s="";
        if(x<0){
            return false;
        }
        while(x>0){
            int rem = x%10;
            x = x/10;
            s+= to_string(rem);

        }
        int n = s.length();
        for (int i=0,j=n-1;i<j;i++,j--){
            if(s[i]!=s[j]){
                return false;
            }
        }
        return true;
    }
};