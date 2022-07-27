class Solution {
public:
    int numTilings(int n) {
        long long mod = 1e9 + 7;
        long long ans = 0;
        
        if (n <= 2){
            return n;
        }
        if (n == 3){
            return 5;
        }
        long long r1 = 1, r2 = 2,r3 = 5;
        for (int i = 4; i <= n; i++){
            ans = r3 * 2 + r1;
            ans %= mod ;
            r1 = r2;
            r2 = r3;
            r3 = ans;
            
            r1 %= mod ;
            r3 %= mod ;
            
            
        }
        return int(ans);
    }
};