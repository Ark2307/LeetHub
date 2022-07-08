// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    int maxi = INT_MAX ;
	    
	    
	    int totalSum = 0 ;
	    for(int i = 0 ; i < n ; i++){
	        totalSum += arr[i] ;
	    }
	    
	    int sum = totalSum / 2 ;
	    int dp[sum + 1] ;
	    fill(dp , dp + sum + 1 , maxi) ;
	    dp[0] = 0 ;
	    for(int i = 0 ; i < n ; i++){
	        for(int j = sum ; j >= arr[i] ; j--){
	            if(dp[j - arr[i]] != maxi){
	                dp[j] = min(dp[j - arr[i]] + 1, dp[j]) ;
	            }
	        }
	    }
	    
	    for(int i = sum ; i >= 0 ; i--){
	        if(dp[i] != maxi)
	            return abs(totalSum - (2 * i)) ;
	    }
	    return totalSum ;
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends