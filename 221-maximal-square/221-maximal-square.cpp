class Solution {
public:
    int maximalSquare(vector<vector<char>>& mat) {
        int n = mat.size() , m = mat[0].size() , maxi = 0 ;
        int matrix[n][m] ;
        
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                matrix[i][j] = (mat[i][j] - '0') ;
                if(matrix[i][j]){
                    maxi = 1 ;
                }
            }
        }
        
        for(int i = n - 2 ; i >= 0 ; i--){
            for(int j = m - 2 ; j >= 0 ; j--){
                if(matrix[i][j] != 0){
                    int c = min(min(matrix[i + 1][j] , matrix[i][j + 1]) , matrix[i + 1][j + 1]) ;
                    matrix[i][j] += c ;
                    int v = matrix[i][j] ;
                    v *= v ;
                    maxi = max(maxi , v) ;
                }
            }
        }
        
        return maxi ;
    }
};