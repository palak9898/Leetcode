class Solution {
public:
    int longestValidParentheses(string s) {
    stack<int> st;
    st.push(-1); // base for the first valid substring
    int maxLen = 0;

    for (int i = 0; i < s.length(); i++) {
        if (s[i] == '(') {
            st.push(i);
        } else { // s[i] == ')'
            st.pop();
            if (!st.empty()) {
                maxLen = max(maxLen, i - st.top());
            } else {
                st.push(i); // reset base index
            }
        }
    }

    return maxLen;
}
};