//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.size();
        int m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        int ans = 0;
        for(int i = 1 ; i <= n ; i++){
            for(int j = 1; j <= m ; j++){
                if(s1[i - 1]==s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans,dp[i][j]);
                } 
                else dp[i][j] = 0;
            }
        }
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s1, s2;
        cin >> s1 >> s2;
        Solution ob;

        cout << ob.longestCommonSubstr(s1, s2) << endl;

        cout << "~"
             << "\n";
    }
}

// } Driver Code Ends