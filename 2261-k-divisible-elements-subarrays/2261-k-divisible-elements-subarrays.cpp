class Solution {
public:
    int countDistinct(vector<int>& nums, int k, int p) {
        unsigned long long int base = 201 ;
        unordered_set<unsigned long long>set ;
        
        for(int i = 0 ; i < (int)nums.size() ; i++){
            unsigned long long hash = 0 ;
            int c = 0 ;
            
            for(int j = i ; j < (int)nums.size() ; j++){
                unsigned long long val = nums[j] ;
                hash = (hash * base) + val ;
                
                c += (nums[j] % p ==0);
                if(c <= k)
                    set.insert(hash);
                
                else break;
            }
        }
        return (int)set.size();
    }
};