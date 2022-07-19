class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size() ;
        int TotalCost = 0 , TotalFuel = 0 ;
        for(int i = 0 ; i < n ; i++){
            TotalCost += cost[i] ;
            TotalFuel += gas[i] ;
        }
        
        if(TotalCost > TotalFuel)
            return -1 ;
        
        int ind , curr = -1 ;
        for(int i = 0 ; i < n ; i++){
            if(curr < 0){
                curr = 0 ;
                ind = i ;
            }
            
            curr += (gas[i] - cost[i]) ;
        }
        
        return ind ;
    }
};