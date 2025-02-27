class Solution {
public:
void findCombinations(int index, vector<int>& candidates, int target, vector<int>& current, vector<vector<int>>& result) {
    // Base case: if target becomes 0, store the combination
    if (target == 0) {
        result.push_back(current);
        return;
    }

    // Iterate through candidates starting from 'index'
    for (int i = index; i < candidates.size(); i++) {
        if (candidates[i] > target) continue; // Skip if the candidate is greater than the target

        // Choose the candidate
        current.push_back(candidates[i]);

        // Recursively call with reduced target and the same index (unlimited usage of the same number allowed)
        findCombinations(i, candidates, target - candidates[i], current, result);

        // Backtrack: remove last added element
        current.pop_back();
    }
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> current;
        findCombinations(0, candidates, target, current, result);
        return result;
    }
};