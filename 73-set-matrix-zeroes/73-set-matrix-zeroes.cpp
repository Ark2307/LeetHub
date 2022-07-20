class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size() , m = matrix[0].size() ;
        
        bool r1 = 0 , c1 = 0 ; 
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(matrix[i][j] == 0){
                    
                    if(i == 0){
                        r1 = 1 ;
                    }
                    
                    if(j == 0){
                        c1 = 1 ;
                    }
                    
                    matrix[i][0] = 0 ;
                    matrix[0][j] = 0 ;
                }
            }
        }
        
        for(int i = 1 ; i < n ; i++){
            for(int j = 1 ; j < m ; j++){
                if(matrix[0][j] == 0 || matrix[i][0] == 0)
                    matrix[i][j] = 0 ;
            }
        }
        
        if(r1){
            for(int i = 1 ; i < m ; i++)
                matrix[0][i] = 0 ;
        }
        
        if(c1){
            for(int i = 1 ; i < n ; i++)
                matrix[i][0] = 0 ;
        }
        return ;
    }
};