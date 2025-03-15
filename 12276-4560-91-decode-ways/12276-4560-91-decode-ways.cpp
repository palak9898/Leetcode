class Solution {
public:
    int numDecodings(string s) {
    if (s.empty() || s[0] == '0') return 0;  // No valid decoding if the string starts with '0'
    
    int n = s.length();
    vector<int> dp(n + 1, 0);
    
    dp[0] = 1;  // Base case: Empty string has one way to decode
    dp[1] = (s[0] != '0') ? 1 : 0;  // Single character decoding (if valid)

    for (int i = 2; i <= n; i++) {
        int oneDigit = s[i - 1] - '0';         // Last single digit
        int twoDigits = stoi(s.substr(i - 2, 2)); // Last two digits

        if (oneDigit >= 1 && oneDigit <= 9)
            dp[i] += dp[i - 1];  // Valid single-digit decoding
        
        if (twoDigits >= 10 && twoDigits <= 26)
            dp[i] += dp[i - 2];  // Valid two-digit decoding
    }

    return dp[n];
}

};