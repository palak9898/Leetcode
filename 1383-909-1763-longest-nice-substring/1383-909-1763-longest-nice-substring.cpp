class Solution {
public:
    bool isNice(const string& str) {
    unordered_set<char> charSet(str.begin(), str.end());
    for (char ch : str) {
        if (charSet.count(tolower(ch)) == 0 || charSet.count(toupper(ch)) == 0) {
            return false;
        }
    }
    return true;
}
    
string longestNiceSubstring(string s) {
        int maxLength = 0;
    string result = "";

    for (int i = 0; i < s.length(); ++i) {
        for (int j = i + 1; j <= s.length(); ++j) {
            string substring = s.substr(i, j - i);
            if (isNice(substring) && substring.length() > maxLength) {
                maxLength = substring.length();
                result = substring;
            }
        }
    }
    return result;
    }
};