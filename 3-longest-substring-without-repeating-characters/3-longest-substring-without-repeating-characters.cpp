class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        
        map<char , int> mp ;
        int currLen = 0 , maxi = 0 , start = 0 ;
        for(int i = 0 ; i < s.size() ; i++){
            if(mp.find(s[i]) == mp.end() || mp[s[i]] < start){
                currLen++;
                mp[s[i]] = i ;
            }
            
            else{
                maxi = max(currLen , maxi) ;
                currLen = i - mp[s[i]] ;
                start = mp[s[i]] + 1;
                mp[s[i]] = i ;
                //cout << start << " " ;
            }
        }
        
        maxi = max(maxi , currLen) ;
        return maxi ;
    }
};