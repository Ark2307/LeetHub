class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int dt) {
        
        int mat[n][n] ;
        int maxi = 1e8 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                
                if(i == j)
                    mat[i][j] = 0 ;
                
                else
                    mat[i][j] = maxi ;
                
            }
        }
        
        for(auto it: edges){
            mat[it[0]][it[1]] = it[2] ;
            mat[it[1]][it[0]] = it[2] ;
        }
        
        for(int k = 0 ; k < n ; k++){
            for(int i = 0 ; i < n ; i++){
                for(int j = 0 ; j < n ; j++){
                    
                    int val = mat[i][k] + mat[k][j] ;
                    mat[i][j] = min(mat[i][j] , val) ;
                    
                }
            }
        }
        
        // cout << mat[2][1] << " " ;
        
        int c = 0 , ans , mini = n + 1 ;
        for(int i = 0 ; i < n ; i++){
            c = 0 ;
            for(int j = 0 ; j < n ; j++){
                
                if(i != j){
                    if(mat[i][j] <= dt)
                        c++ ;
                }
                
            }
            if(c <= mini){
                ans = i ;
                mini = c ;
            }
        }
        return ans ;
        
    }
};