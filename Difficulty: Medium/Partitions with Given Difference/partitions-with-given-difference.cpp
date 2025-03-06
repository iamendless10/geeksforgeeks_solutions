//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends




class Solution {
  public:
    int solve(vector<int> &arr, int target, int idx, vector<vector<int>> &dp) {
        if(idx == arr.size()){
            return target == 0 ? 1: 0;
        }
        if(dp[idx][target] != -1)   return dp[idx][target];
        int not_take = solve(arr, target, idx + 1, dp);
        int take = 0;
        if(arr[idx] <= target) {
            take = solve(arr, target - arr[idx], idx + 1, dp);
        }
        return dp[idx][target] = take + not_take;
    }
    int countPartitions(vector<int>& arr, int d) {
        // Code here
        int total_sum = accumulate(arr.begin(), arr.end(), 0);
        if((total_sum - d) % 2 != 0 || total_sum < d || arr.size() == 1)   return 0;
        int sum = (total_sum - d) / 2;
        vector<vector<int>> dp(arr.size(), vector<int>(sum + 1, -1));
        return solve(arr, sum, 0, dp);
    }
};



//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.countPartitions(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends