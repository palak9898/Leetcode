class Solution {
public:
    vector<vector<int>> result;
    int n;

    void solve(vector<int>& temp, vector<int>& nums, vector<bool>& used) {
        if (temp.size() == n) {
            result.push_back(temp);
            return;
        }
        
        for (int i = 0; i < n; i++) {
            if (!used[i]) {  
                used[i] = true;
                temp.push_back(nums[i]);
                solve(temp, nums, used);
                temp.pop_back();
                used[i] = false;
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        result.clear();  // Clear the result to avoid previous data persistence
        n = nums.size();
        vector<int> temp;
        vector<bool> used(n, false);
        solve(temp, nums, used);
        return result;
    }
};
