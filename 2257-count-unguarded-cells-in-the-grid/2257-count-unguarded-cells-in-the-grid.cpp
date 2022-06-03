class Solution {
public:
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        int mat[m][n] ;
        memset(mat , 0 , sizeof(mat)) ;
        
        for(int i = 0 ; i < guards.size() ; i++){
            mat[guards[i][0]][guards[i][1]] = -1 ;
        }
        
        for(int i = 0 ; i < walls.size() ; i++){
            mat[walls[i][0]][walls[i][1]] = 1 ;
        }
        
        for(int i = 0 ; i < guards.size() ; i++){
            int r = guards[i][0] , c = guards[i][1] ;
            
            // move left {same row , col decrease}
            for(int j = c - 1 ; j >= 0 ; j--){
                if(mat[r][j] == 1 || mat[r][j] == -1)
                    break ;
                
                mat[r][j] = 2 ;
            }
            
            // move right {same row , col increase}
            for(int j = c + 1 ; j < n ; j++){
                if(mat[r][j] == 1 || mat[r][j] == -1)
                    break ;
                
                mat[r][j] = 2 ;
            }
            
            // move up {same col , row decrease}
            for(int j = r - 1 ; j >= 0 ; j--){
                if(mat[j][c] == 1 || mat[j][c] == -1)
                    break ;
                
                mat[j][c] = 2 ;
            }
            
            // move up {same col , row increase}
            for(int j = r + 1 ; j < m ; j++){
                if(mat[j][c] == 1 || mat[j][c] == -1)
                    break ;
                
                mat[j][c] = 2 ;
            }
        }
        
        int res = 0 ;
        for(int i = 0 ; i < m ; i++){
            for(int j = 0 ; j < n ; j++){
                if(mat[i][j] == 0)
                    res++ ;
            }
        }
        
        return res ;
    }
};