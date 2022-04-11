class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size() ;
        sort(nums.begin() , nums.end()) ;
        
        vector<int>::iterator itr , itr1;
        int res = INT_MAX ,ans;
        
        for(int i = 0 ; i < n - 2 ; i++){
            for(int j = i + 1 ; j < n - 1 ; j++){
                int val = target - nums[i] - nums[j] ;
                itr = nums.begin() ;
                advance(itr , j) ;
                itr++ ;
                
                itr1 = upper_bound(itr , nums.end() , val) ;
                //cout << itr1 - nums.begin() << " " << val << " " ;
                if(itr1 != nums.end())
                {
                    int x = *itr1 ;
                    int diff = abs(target - x - nums[i] - nums[j]) ;
                    if(diff < res){
                        res = diff ;
                        ans = x + nums[i] + nums[j] ;
                    }
                }
                
                if(itr1 != itr)
                    itr1-- ;
                
                int x = *itr1 ;
                //cout << x << " " ;
                int diff = abs(target - x - nums[i] - nums[j]) ;
                if(diff < res){
                    res = diff ;
                    ans = x + nums[i] + nums[j] ;
                }
            }
        }
        return ans ;
    }
};