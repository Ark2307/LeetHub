class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size() ;
        int pos = -1 ;
        
        for(int i = 0 ; i < n - 1 ; i++){
            if(nums[i] < nums[i + 1]){
                pos = i ;
            }
        }
        
        if(pos == -1){
            reverse(nums.begin() , nums.end()) ;
        }
        
        else{
            vector<int> temp ;
            int mini = nums[pos + 1] , ind = pos + 1 ;
            for(int i = pos + 1 ; i < n ; i++){
                if(mini > nums[i] && nums[i] > nums[pos]){
                    mini = nums[i] ;
                    ind = i ;
                }
            }
            swap(nums[pos] , nums[ind]) ;
            
            for(int i = pos + 1 ; i < n ; i++){
                temp.push_back(nums[i]) ;
            }
            sort(temp.begin() , temp.end()) ;
            for(int i = 0 ; i < temp.size() ; i++){
                nums[pos + 1 + i] = temp[i] ;
            }
        }
        
    }
};