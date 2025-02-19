class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int startIndex;
        
        int totalg = 0 ; 
        int totalc = 0;
        for(int i = 0 ; i < n ; i ++){
            totalg += gas[i];
            totalc += cost[i];
        }
        int sIndex=0;
        if(totalg < totalc) return -1;
        int tank =0 ;
        for(int i = 0 ; i < n ;i++){
            tank += gas[i] - cost[i];
            if(tank< 0 ){
                tank = 0 ;

                sIndex = i+1;
            }
        }
        return sIndex;
        
    }
};