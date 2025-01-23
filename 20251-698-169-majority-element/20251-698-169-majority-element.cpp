class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> kMap;
        int n = nums.size();
        for(auto ch : nums){
           kMap[ch]++;
        }
        for(auto [key,value] : kMap){
            if(value > n/2){
                return key;
            }
        }
        return -1;
        
    }
};