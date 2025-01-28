//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  private:
    bool cc(vector<int> &arr, int target, int n, vector<vector<int>> &dp){
        if (target == 0) return true;            // A sum of 0 is always possible with an empty subset
        if (n < 0) return false;

        bool pick = false;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        if (arr[n] <= target){
            pick = cc(arr, target - arr[n], n - 1,dp); 
        }
        
        bool notpick = cc(arr, target, n - 1,dp);
        return dp[n][target] = pick || notpick; 
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(target + 1, -1)); 
        return cc(arr, target, arr.size() - 1,dp);
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int sum;
        cin >> sum;
        cin.ignore();

        Solution ob;
        if (ob.isSubsetSum(arr, sum))
            cout << "true" << endl;
        else
            cout << "false" << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends