class Solution {
public:
    void backtrack(vector<int>& nums, int start, vector<int>& subset, vector<vector<int>>& result) {
    result.push_back(subset); // Store the current subset

    for (int i = start; i < nums.size(); i++) {
        subset.push_back(nums[i]); // Choose
        backtrack(nums, i + 1, subset, result); // Explore
        subset.pop_back(); // Unchoose
    }
}

vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> result;
    vector<int> subset;
    backtrack(nums, 0, subset, result);
    return result;
}
};