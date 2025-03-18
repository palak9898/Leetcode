class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int start = 0, max_length = 0, bitwise_and =0;

        for(int right = 0; right< n; right++){
            while((bitwise_and & nums[right])!= 0){
                bitwise_and ^= nums[start];
                start++;
            }
            bitwise_and |= nums[right];  
            max_length = max(max_length, right- start +1);

        }
        return max_length;
        

    }
};