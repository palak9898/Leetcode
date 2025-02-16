class Solution {
public:
    bool solve(int i, int n, vector<int>& result, vector<int>& used) {
        if (i >= result.size()) {
            return true;
        }
        if (result[i] != -1) {
            return solve(i + 1, n, result, used);
        }

        for (int num = n; num >= 1; num--) {
            if (used[num]) continue;

            used[num] = true;
            result[i] = num;

            if (num == 1) { // '1' only occupies a single position
                if (solve(i + 1, n, result, used)) {
                    return true;
                }
            } else {
                int j = i + num; // Position where the second occurrence of 'num' should be
                if (j < result.size() && result[j] == -1) {
                    result[j] = num;
                    if (solve(i + 1, n, result, used)) {
                        return true;
                    }
                    result[j] = -1; // Backtrack
                }
            }

            used[num] = false; // Reset usage flag
            result[i] = -1; // Reset the position
        }

        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> result(2 * n - 1, -1);
        vector<int> used(n + 1, false);
        solve(0, n, result, used);
        return result;
    }
};
