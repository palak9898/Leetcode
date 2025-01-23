class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> nums1;
        vector<int> nums2;

        int n = nums.size();
        k=k%n;
        for(int i=n-k;i<n;i++){
            nums1.push_back(nums[i]);
        }
        for(int i=0;i<n-k;i++){
            nums2.push_back(nums[i]);
        }
        for(int j=0;j<n-k;j++){
            nums1.push_back(nums2[j]);
        }
        nums=nums1;
    }
};