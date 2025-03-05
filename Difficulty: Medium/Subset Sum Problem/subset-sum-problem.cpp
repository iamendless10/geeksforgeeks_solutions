//{ Driver Code Starts

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function template for C++

class Solution {
  private:
    bool cc(int ind, int target, vector<int> &arr, vector<vector<int>> &dp){
        if(target == 0) return true;
        if(ind == 0 ) return (arr[0] == target);
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        bool notpick = cc(ind - 1, target, arr, dp);
        
        bool pick = false;
        
        if(arr[ind] <= target){
            pick = cc(ind - 1, target - arr[ind], arr, dp);
        }
        
        return dp[ind][target] =  pick | notpick;   
    }
  public:
    bool isSubsetSum(vector<int>& arr, int target) {
        // code here
        vector<vector<int>> dp(arr.size(), vector<int> (target + 1, -1));
        return cc(arr.size() - 1, target, arr, dp);
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