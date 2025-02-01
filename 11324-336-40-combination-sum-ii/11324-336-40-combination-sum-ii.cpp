class Solution {
public:
void backtrack(int start, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& result) {
    if (target == 0) {
        result.push_back(path);
        return;
    }

    for (int i = start; i < candidates.size(); i++) {
        if (i > start && candidates[i] == candidates[i - 1]) continue; // Skip duplicates
        if (candidates[i] > target) break; // Stop if the number exceeds target
        
        path.push_back(candidates[i]);
        backtrack(i + 1, target - candidates[i], candidates, path, result); // Move to next index
        path.pop_back(); // Backtrack
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
    vector<vector<int>> result;
    vector<int> path;
    backtrack(0, target, candidates, path, result);
    return result;
    }
};