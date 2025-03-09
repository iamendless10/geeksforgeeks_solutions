//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  private:
    int cc(int ind, vector<int> &val, vector<int> &wt, int capacity, vector<vector<int>> &dp){
        
        if (ind == 0) {  
            return (capacity/wt[0]) * val[0];
        }
        
        if(dp[ind][capacity] != -1) return dp[ind][capacity];
        
        int notpick =0 + cc(ind - 1, val, wt, capacity, dp);
        int pick = 0;
        
        if(wt[ind] <= capacity){
            pick = val[ind] + cc(ind, val, wt, capacity - wt[ind], dp);
        }
        
        return dp[ind][capacity] = max(pick,notpick);
    }
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>>dp(n , vector<int> (capacity + 1, -1));
        return cc(n - 1, val, wt, capacity, dp);
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int W;
        cin >> W;
        cin.ignore();
        string str;
        getline(cin, str);
        stringstream ss(str);
        vector<int> val;
        int num;
        while (ss >> num) {
            val.push_back(num);
        }
        string str2;
        getline(cin, str2);
        stringstream ss2(str2);
        vector<int> wt;
        int num2;
        while (ss2 >> num2) {
            wt.push_back(num2);
        }
        Solution ob;
        cout << ob.knapSack(val, wt, W) << endl;
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends