class Solution {
public:
    
    int funct(int n , int &k){
        if(n == 1){
            return 0 ;
        }
        
        n-- ;
        int val = n ;
        while(n > 1 && k >= val){
            val *= (n - 1) ;
            n-- ;
        }
        
        
        int ind = k / val ;
        k %= val ;
        return ind ;
    }
    
    string getPermutation(int n, int k) {
        string res = "" ;
        
        set<int> st ;
        set<int>::iterator itr ;
        
        for(int i = 1 ; i <= n ; i++)
            st.insert(i) ;
        
        itr = st.begin() ;
        
        k-- ;
        
        for(int i = 0 ; i < n ; i++){
            int x = funct(n - i , k) ;
            advance(itr , x) ;
            
            char a = *itr + '0' ;
            res += a ;
            st.erase(itr) ;
            itr = st.begin() ;
        }
        return res ;
    }
};