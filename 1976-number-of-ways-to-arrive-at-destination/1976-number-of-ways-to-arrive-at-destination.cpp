#define ll long long
#define pli pair<ll , ll>

const ll mod = 1e9 + 7 ;
const ll maxi = 1e18 + 10 ;

class Solution {
public:
    
    ll minTime(vector<vector<pli>> &adj , int n){
        
        priority_queue<pli , vector<pli> , greater<pli>> pq ;
        pq.push({0 , 0}) ;
        
        vector<ll> dist(n , maxi) ;
        
        ll res = 0 ;
        
        while(!pq.empty()){
            
            ll node = pq.top().second ;
            ll curr = pq.top().first ;
            
            if(node == (n - 1))
                return curr ;
            
            pq.pop() ;
            
            for(auto it: adj[node]){
                
                ll time = curr + it.second ;
                if(time < dist[it.first]){
                    dist[it.first] = time ; 
                    pq.push({time , it.first}) ;
                }
            }
        }
        return dist[n - 1] ;
    }
    
    ll count(vector<vector<pli>> &adj , int n , ll minTime){
        
        vector<ll> dp(n , 0) ;
        vector<ll> dist(n , maxi) ;
        
        dp[0] = 1 ;
        priority_queue<pli , vector<pli> , greater<pli>> pq ;
        pq.push({0 , 0}) ;
        
        dist[0] = 0 ;
        
        while(!pq.empty()){
            
            ll node = pq.top().second , curr = pq.top().first ;
            pq.pop() ;
            
            
            for(auto it: adj[node]){
                
                ll val = curr + it.second ;
                if(val <= minTime && dist[it.first] > val){
                    dp[it.first] = dp[node] ;
                    dist[it.first] = val ;
                    pq.push({val , it.first}) ;
                }
                
                else if(dist[it.first] == val){
                    dp[it.first] += dp[node] ;
                    dp[it.first] %= mod ;
                }
                
            }
            
        }
        
        return dp[n - 1] ;
    }
    
    int countPaths(int n, vector<vector<int>>& roads) {
        
        vector<vector<pli>> adj(n) ;
        for(auto it: roads){
            
            adj[it[0]].push_back({it[1] , it[2]}) ;
            adj[it[1]].push_back({it[0] , it[2]}) ;
            
        }
        
        ll mini = minTime(adj , n) ;
        // return mini ;
        
        ll c = count(adj , n , mini) ;
        return int(c) ;
    }
};