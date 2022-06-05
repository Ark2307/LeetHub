class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        set<vector<int>> si ;
        
        for(int i = 0 ; i < nums.size() ; i++){
            int c = 0 ;
            vector<int> vi ;
            for(int j = i ; j < nums.size() ; j++){
                vi.push_back(nums[j]) ;
                if((nums[j] % p) == 0)
                    c++ ;
                
                if(c <= k){
                    si.insert(vi) ;
                }
                
                else
                    break ;
            }
        }
        
        // for(auto it: si){
        //     cout << it.first << " " << it.second << " " << "\n" ;
        // }
        
        int ans = si.size() ;
        return ans ;
    }
};