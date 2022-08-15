#define pi pair<int , int>

class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        
        vector<vector<int>> adj(n + 1) ;
        for(auto it: edges){
            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
        }
        
        priority_queue<pi , vector<pi> , greater<pi>> pq ;
        pq.push({0 , 1}) ;
        
        int maxi = INT_MAX ;
        
        vector<int> freq(n + 1 , 0) ;
        vector<int> dist(n + 1 , maxi) ;
        
        bool flag = 0 ;
        
        dist[1] = 0 ;
        
        while(!pq.empty()){
            
            int node = pq.top().second ;
            int curr = pq.top().first ;
            pq.pop() ;
            
            int signal = curr/change;
            if(signal % 2){
                curr += (((signal + 1) * change) - curr);
            }
            
            curr += time ;
            // cout << node << " " << curr << "\n" ;
            
            for(auto it: adj[node]){
                
                if(freq[it] < 2 && curr != dist[it]){
                    
                    if(flag && (it == n))
                        return curr ;
                    
                    if(it == n)
                        flag = 1 ;
                    
                    freq[it]++ ;
                    dist[it] = curr ;
                    pq.push({curr , it}) ;
                }
                
            }

        }
        return dist[n] ;
    }
};