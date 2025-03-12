//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    int cc(int ind, int n, vector<int> &price, vector<vector<int>> &dp){
        if(ind == 0){
            return n * price[0];
        }
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        int notpick = 0 + cc(ind - 1, n, price, dp);
        int pick = INT_MIN;
        int rod_len = ind + 1;
        
        if(rod_len <= n)    pick = price[ind] + cc(ind, n - rod_len, price, dp);
        
        return dp[ind][n] = max(pick,notpick);
    }
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return cc(n - 1, n, price, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    scanf("%d ", &t);
    while (t--) {

        vector<int> a;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            a.push_back(number);
        }

        Solution ob;

        cout << ob.cutRod(a) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends