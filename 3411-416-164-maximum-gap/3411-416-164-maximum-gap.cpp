class Solution {
public:
    void countSort(vector<int>& nums,long long exp){
        int n =nums.size();
        vector<int> output(n);
        int count[10] = {0};

        for(int i=0;i<n;i++){
            count[(nums[i]/exp) % 10]++;
        }
        for (int i = 1; i < 10; i++)
        count[i] += count[i - 1];

        for (int i = n - 1; i >= 0; i--) {
        int digit = (nums[i] / exp) % 10;

        output[count[digit] - 1] = nums[i];
        count[digit]--;
    }

    // Copy output to nums
    for (int i = 0; i < n; i++)
        nums[i] = output[i];
    }
    int getMax(vector<int>& nums){
        int max = nums[0];
        for(int i=0;i<nums.size();i++){
            if(max < nums[i]){
            max = nums[i];
            }
        }
        return max;   
    }
    void radixSort(vector<int>& nums){
        int maxVal = getMax(nums);
        for(long long exp =1; maxVal/exp >0; exp*=10 ){
            countSort(nums,exp);
        }
    }
  
    int maximumGap(vector<int>& nums) {
        vector<int> arr;
        int n = nums.size();
        if(n<2){
            return 0;
        }
        radixSort(nums);

        int maxGap =0;
        for(int i=1;i<nums.size();i++){
            maxGap = max(maxGap, nums[i] - nums[i-1]);
        }
        return maxGap;   
    }

};