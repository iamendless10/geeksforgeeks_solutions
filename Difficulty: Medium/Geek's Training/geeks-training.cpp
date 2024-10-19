//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maximumPoints(vector<vector<int>>& arr, int n) {
        // Code here
        vector<vector<int>> dp(n, vector<int>(4, -1));
        return f(n-1, 3, arr, dp);
    }
    
    
    int f(int day, int last, vector<vector<int>>& arr, vector<vector<int>>& dp) {
   
        if (day == 0) {
            int maxi = 0;
            for (int task = 0; task < 3; task++) {
                if (task != last) {
                    maxi = max(maxi, arr[0][task]);
                }
            }
            return maxi;
        }
    
      
        if (dp[day][last] != -1) return dp[day][last];
    
        int maxi = 0;
        for (int task = 0; task < 3; task++) {
            if (task != last) {
                int points = arr[day][task] + f(day - 1, task, arr, dp);
                maxi = max(maxi, points);
            }
        }
    
        return dp[day][last] = maxi; 
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> arr;
        for (int i = 0; i < n; ++i) {
            vector<int> temp;
            for (int j = 0; j < 3; ++j) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            arr.push_back(temp);
        }

        Solution obj;
        cout << obj.maximumPoints(arr, n) << endl;
    }
    return 0;
}
// } Driver Code Ends