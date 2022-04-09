class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        int n = nums.size() ;
        
        set<vector<int>> st ;
        
        for(int i = 0 ; i < n - 2 ; i++){
            int lo = i + 1 , hi = n - 1 ;
            int reqSum = -1 * nums[i] ;
            while(lo < hi){
                int currSum = nums[lo] + nums[hi] ;
                if(currSum == reqSum){
                    vector<int> vi = {nums[i] , nums[lo] , nums[hi]} ;
                    st.insert(vi) ;
                    while((lo < hi) && nums[lo] == nums[lo + 1]){
                        lo++ ;
                    }
                    lo++ ;
                }
                else if(currSum > reqSum){
                    hi-- ;
                }
                
                else
                    lo++ ;
            }
        }
        
        vector<vector<int>> res ;
        for(auto itr = st.begin() ; itr != st.end() ;itr++){
            res.push_back(*itr) ;
        }
        return res ;
    }
};