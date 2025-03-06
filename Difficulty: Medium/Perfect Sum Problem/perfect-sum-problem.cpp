//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int cc(int ind, vector<int> &arr, int target, vector<vector<int>> &dp){
        if (ind == 0) {
            if (target == 0 && arr[0] == 0) return 2; // Two cases: {} and {0}
            if (target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notpick = cc(ind - 1, arr, target,dp);
        int pick = 0;
        
        if(arr[ind] <= target){
            pick = cc(ind - 1, arr, target - arr[ind], dp);
        }
        
        return dp[ind][target] = pick + notpick;
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        vector<vector<int>> dp(arr.size(), vector<int> (target + 1, -1));
        return cc(arr.size() - 1, arr, target , dp);
        // code here
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore newline character after t

    while (t--) {
        vector<int> arr;
        int target;
        string inputLine;

        getline(cin, inputLine); // Read the array input as a line
        stringstream ss(inputLine);
        int value;
        while (ss >> value) {
            arr.push_back(value);
        }

        cin >> target;
        cin.ignore(); // Ignore newline character after target input

        Solution solution;
        cout << solution.perfectSum(arr, target);
        cout << "\n~\n";
    }

    return 0;
}

// } Driver Code Ends