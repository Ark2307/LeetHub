class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int ele1 = INT_MAX , ele2 = ele1 , c1 = 0 , c2 = 0 , n = nums.size();
        
        
        for(int i = 0 ; i < nums.size() ; i++){
            
            if(ele1 == nums[i])
                c1++ ;
            
            else if(ele2 == nums[i])
                c2++ ;
            
            else if(c1 == 0){
                ele1 = nums[i] ;
                c1++ ;
            }
            
            else if(c2 == 0){
                ele2 = nums[i] ;
                c2++ ;
            }
            
            else{
                c1-- ;
                c2-- ;
            }
        }
        
        int val = (n + 2) / 3 ;
        c1 = 0 , c2 = 0 ;
        for(int i = 0 ; i < n ; i++){
            if(nums[i] == ele1){
                c1++ ;
            }
            
            else if(nums[i] == ele2)
                c2++ ;
        }
        
        vector<int> res ;
        if((n % 3) != 0){
            if(c1 >= val)
                res.push_back(ele1) ;
        
            if(c2 >= val)
                res.push_back(ele2) ;
        }
        
        else{
            if(c1 > val)
                res.push_back(ele1) ;
        
            if(c2 > val)
                res.push_back(ele2) ;

        }
        return res; 
    }
};