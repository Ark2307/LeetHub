class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        multiset<int , greater<int>> st ;
        
        vector<pair<int , int>> vi ;
        for(auto it: buildings){
            
            vi.push_back({it[0] , (-1 * it[2])}) ;
            vi.push_back({it[1] , it[2]}) ;
            
        }
        
        sort(vi.begin() , vi.end()) ;
        
        vector<vector<int>> res ;
        
        st.insert(0) ;
        int i = 0 , n = vi.size() ;
        int maxi = 0 ;
        while(i < n){
            
            if(vi[i].second < 0){
                st.insert(-1 * vi[i].second) ;
            }
            
            else{
                st.erase(st.find(vi[i].second)) ;
            }
            
            int val = *(st.begin()) ;
            if(val != maxi){
                
                res.push_back({vi[i].first , val}) ;
                maxi = val ;
                
            }
            i++ ;
        }
        
        return res ;
    }
};