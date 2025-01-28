//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    int cc(int n, vector<int> &val, vector<int> &wt, int capacity, vector<vector<int>> &dp){
        
        if(dp[n][capacity] != -1) return dp[n][capacity];
        
        if (n < 0) return 0;
        
        if (n == 0) {
            return dp[n][capacity] = (wt[n] <= capacity) ? val[n] : 0;
        }
        
        if(wt[n] > capacity){
            return dp[n][capacity] = cc(n - 1, val, wt, capacity, dp);
        }
        
        
        int notpick = 0 + cc(n - 1, val, wt, capacity, dp);
        int pick = val[n] + cc(n - 1, val, wt, capacity - wt[n],dp);
        
        
        return dp[n][capacity] = max(pick, notpick);
    }
  public:
    // Function to return max value that can be put in knapsack of capacity.
    int knapSack(int capacity, vector<int> &val, vector<int> &wt) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n, vector<int>(capacity + 1, -1));
        return cc(n - 1, val, wt,capacity, dp);
    }
};

//{ Driver Code Starts.

int main() {
    // Taking total test cases
    int testCases;
    cin >> testCases;
    cin.ignore();
    while (testCases--) {
        // Reading number of items and capacity
        int numberOfItems, capacity;
        vector<int> weights, values;
        string input;
        int number;

        // Read capacity and number of items
        getline(cin, input);
        stringstream ss(input);
        ss >> capacity;      // The first number is the capacity
        ss >> numberOfItems; // The second number is the number of items

        // Read values
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            values.push_back(number);
        }

        // Read weights
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            weights.push_back(number);
        }

        Solution solution;
        cout << solution.knapSack(capacity, values, weights) << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends