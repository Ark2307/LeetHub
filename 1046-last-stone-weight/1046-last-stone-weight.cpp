class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        multiset<int> st ;
        int n = stones.size() ;
        for(int i = 0 ; i < n ; i++){
            st.insert(stones[i]) ;
        }
        
        set<int>::iterator itr ;
        while(!st.empty()){
            if(st.size() == 1)
                break ;
            
            itr = st.end() ;
            itr-- ;
            int val = *itr ;
            st.erase(itr) ;
            
            itr = st.end() ;
            itr-- ;
            int temp = *itr ;
            st.erase(itr) ;
            
            if(val == temp){
                continue ;
            }
            
            st.insert(val - temp) ;
        }
        
        if(st.empty())
            return 0 ;
        
        itr = st.begin() ;
        return *itr ;
    }
};