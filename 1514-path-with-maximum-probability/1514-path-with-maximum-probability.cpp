class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        
        
        vector<pair<int , double>> adj[n] ;
        int c = 0 ;
        for(auto it : edges){
            
            adj[it[0]].push_back({it[1] , succProb[c]}) ;
            adj[it[1]].push_back({it[0] , succProb[c]}) ;
            
            c++ ;
        }
        
        vector<double> prob(n , 0) ;
        prob[start] = 1.0 ;
        
        priority_queue<pair<double , int>> pq ;
        pq.push({prob[start] , start}) ;
        
        while(!pq.empty()){
            
            int node = pq.top().second ;
            double curr = pq.top().first ;
            
            pq.pop() ;
            
            for(auto it: adj[node]){
                
                double val = curr * it.second ;
                if(val > prob[it.first]){
                    prob[it.first] = val ;
                    pq.push({val , it.first}) ;
                }
                
            }
            
        }
        return prob[end] ;
        
    }
};