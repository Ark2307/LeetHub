class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size() ;
        int ans[n] ;
        fill(ans , ans + n , 1) ;
        
        for(int i = 0 ; i < n - 1 ; i++){
            if(ratings[i] < ratings[i + 1] && ans[i] >= ans[i + 1])
                ans[i + 1] = ans[i] + 1;
        }
        
        
        int sum = 0 ;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i + 1] && ans[i] <= ans[i + 1]){
                ans[i] = ans[i + 1] + 1;
            }
            sum += ans[i] ;
        }
        sum += ans[n - 1] ;
        return sum ;
    }
};