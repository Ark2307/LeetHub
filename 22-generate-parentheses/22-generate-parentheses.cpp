class Solution {
public:
    void funct(int n , int start , int end , string str , vector<string> &res){
        if(start == n && end == n){
            res.push_back(str) ;
            return ;
        }
        
        if(start < n){
            funct(n , start + 1 , end , str + "(" , res) ;
        }
        
        if(end < start){
            funct(n , start , end + 1 , str + ")" , res) ;
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res ;
        if(n == 1){
            res.push_back("()") ;
            return res ;
        }
        
        if(n == 2){
            res.push_back("()()") ;
            res.push_back("(())") ;
            return res ;
        }
        
        funct(n , 0 , 0 , "" , res) ;
        return res ;
    }
};