//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  int f(int n, vector<int> &height, vector<int> &dp) {
    if (n == 0) return 0;
   
    if(dp[n] != -1) return dp[n];
    
    int left = f(n - 1, height, dp) + abs(height[n] - height[n - 1]);
    
    int right = INT_MAX;

    if (n > 1) {
        right = f(n - 2, height, dp) + abs(height[n] - height[n - 2]);
    }

    dp[n] = min(left, right);
    
    return dp[n];
}

int minimumEnergy(vector<int>& height, int n) {
    vector<int> dp(n+1 , -1);
    return f(n - 1, height, dp);
}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        Solution obj;
        cout << obj.minimumEnergy(arr, N) << "\n";
    }
    return 0;
}
// } Driver Code Ends